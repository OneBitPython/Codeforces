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

int f(int x, int ns, int i, int k){
    return (ns+20*x)*(k-i-4*x);
}

void solve()
{

    int s,k;
    cin >> s >> k;
    
    if((s%10)==0){
        cout << s*k << endl;
        return;
    }
    if((s%10)==5){
        cout << max(s*k,(s+5)*(k-1)) << endl;
        return;
    }
    int curr = s%10;
    int tot = 0;
    int res = 0;
    set<int>imp = {2,4,6,8};
    while(!imp.count(s%10) && k>0){
        res = max(res, s*k);
        s+=(s%10);
        k--;
        res = max(res, s*k);
    }
    curr = (s%10);
    for(int i = 0;i<=min(k,4ll);++i){
        int ns = s+tot;
        // cost is (ns+20x)*(k-(i+4x))
        // i+4x <= k -> x <= (k-i)/4
        int l = 0, r = (k-i)/4;
        while(l + 2 < r){
            int m1 = l+(r-l)/3, m2 = r-(r-l)/3;
            if(f(m1,ns,i,k) < f(m2,ns,i,k))l = m1;
            else r = m2;
        }
        for(int j = l;j<=r;++j)res = max(res, f(j,ns,i,k));
        tot+=curr;
        curr*=2;
        curr%=10;
    }
    cout << res << endl;
}   
// 4
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