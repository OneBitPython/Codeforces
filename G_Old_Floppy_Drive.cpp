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


int give(int x, vector<pair<int,int>>&b, vector<int>&c){
    // binary search on first in dex in b that's greater than x
    int l = 0, r = (int)(b.size())-1;
    int res = 1e18;
    while(l <= r){
        int m = (l+r)/2;
        if(b[m].first < x)l = m+1;
        else res = min(res,c[m]), r = m-1;
    }
    return res;
}
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<pair<int,int>>b;
    int sum = 0, mx = 0;
    for(int i = 1;i<=n;++i){
        sum+=a[i];
        mx = max(mx, sum);
        b.pb({sum,i});
    }
    sort(all(b));
    vector<int>c(n+1);
    c.back() = 1e18;
    for(int i = n-1;i>=0;--i)c[i] = min(c[i+1],b[i].second);
    while(q--){
        int x;
        cin >> x;
        if(x <= mx){
            //TODO
            cout << give(x,b,c)-1 << ' ';
            continue;
        }
        if(sum <= 0){
            cout << -1 << ' ';
            continue;
        }
        int need = x-mx;
        int times = (need+sum-1)/sum;
        int left = x-(times*sum);
        cout << give(left,b,c)-1+(times*n) << ' ';
    }
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