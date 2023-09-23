#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");} 

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

int give(int A, int B, int k){
    int res = 2e9, l = 0, r = 2e9;
    while(l <= r){
        int m = (l+r)/2;
        int low = B*(m+1), high = ((2*A)-1+(A*m));
        int y = (k-low)/A;
        if(low <= high && y >= 0 && (k-(A*y))>=low && (k-(A*y))<=high)res = y, l = m+1;
        else r = m-1;
        
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<pair<int,int>>b = {{0,0}}; // stores {money to pay, i}
    int mn = 2e9;
    // if for an i, there exists a j (j > i) such that a[j] < a[i] then 'i' is useless
    
    for(int i = n;i>=1;--i){
        if(a[i] < mn)b.pb({a[i], i});
        mn= min(mn, a[i]);
    }
    int m = (int)(b.size())-1;
    reverse(b.begin()+1, b.end());
    int k;
    cin >> k;

    vector<int>pos(n+1);

    for(int i = 1;i<=m;++i){
        if(i != m){
            int A = b[i].first, B = b[i+1].first;
            int idx = b[i].second;
            if((2*A) < B){
                // use only A till coins are gone
                int ops = k/A;
                pos[idx] += ops;
                break;
            }
            // choose to do operations with A until either k is over or k/A = k/B
            int op = min(k/A,give(A,B,k));
            k-=(op*A);
            pos[idx] += op;
        }else{
            // finish k
            int A = b[i].first, idx = b[i].second;
            int ops = k/A;
            pos[idx] += ops;
        }
    }
    vector<int>res(n+1);
    int tot = 0;
    for(int i = n;i>=1;--i){
        tot+=pos[i];
        res[i] = tot;
    }
    for(int i =1 ;i<=n;++i)cout << res[i] << ' ';
    cout << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}