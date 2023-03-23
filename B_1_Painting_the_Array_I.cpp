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


int nxt(vector<vector<int>>&idx, int v, int i){
    auto c = upper_bound(all(idx[v]), i);
    if(c==idx[v].end())return 1e18;
    return *c;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    int res = 0, l1 = 0, l2 = 0;
    vector<vector<int>>idx(n+1);
    for(int i = 1;i<=n;++i)idx[a[i]].pb(i);
    vector<int>f={-1},s={-1};
    for(int i = 1;i<=n;++i){
        if(a[i]==l1){
            s.pb(a[i]);
            l2 = a[i];
        }else if(a[i]==l2){
            f.pb(a[i]);
            l1 = a[i];
        }else{
            int nxt1 = nxt(idx,l1,i), nxt2 = nxt(idx, l2, i);
            if(nxt1 < nxt2)l1 = a[i],f.pb(a[i]);
            else l2 = a[i],s.pb(a[i]);
        }
    }
    for(int i = 1;i<(int)(f.size());++i)res+=(f[i]!=f[i-1]);
    for(int i = 1;i<(int)(s.size());++i)res+=(s[i]!=s[i-1]);
    cout << res;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}