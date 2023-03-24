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


vector<vector<int>>edges;
int n,m;
int res = 0;
const int mxn = 2e5+1;
int id[mxn],sz[mxn];
int root(int x){
    if(x==id[x])return x;
    return id[x] = root(id[x]);
}

bool merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return 0;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
    return 1;
}

bool construct(int x){
    // construct spanning tree where edges don't have any bit of x set
    int got = 0;
    for(int i = 0;i<=n;++i)id[i] = i,sz[i] = 1;
    int val = 0;
    for(auto y : edges){
        if((y[2]&x) > 0)continue;
        if(merge(y[0],y[1]))got++,val|=y[2];
    }
    if(got==(n-1)){
        res = min(res, val);return 1;
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    edges.clear();
    for(int i = 0;i<m;++i){
        int u,v,w;
        cin >> u >> v >> w;
        edges.pb({u, v, w});
    }
    int x = 0;
    for(int i = 30;i>=0;--i){
        x+=(1ll<<i);
        if(!construct(x))x-=(1ll<<i);
    }
    int res = 0;
    for(int i = 0;i<=30;++i){
        if(x&(1ll<<i)){

        }else res+=(1ll<<i);
    }
    cout << res << endl;
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