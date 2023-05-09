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

vector<int>id,sz,mx,mn;
int root(int x){
    if(id[x]==x)return x;
    return id[x] = root(id[x]);
}
void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
    mn[u] = min(mn[u], mn[v]);
    mx[u] = max(mx[u], mx[v]);
}


void solve()
{
    int n,k;
    cin>> n >> k;
    id.resize(n+1);
    sz.resize(n+1);
    mx.resize(n+1);
    mn.resize(n+1);
    for(int i = 1;i<=n;++i)id[i] = i,sz[i] = 1, mn[i] = i,mx[i] = i;
    while(k--){
        string s;
        cin >> s;
        
        if(s=="get"){
            int u;
            cin >> u;
            u = root(u);
            cout << mn[u] << ' ' << mx[u] << ' ' << sz[u] << endl;
        }else{
            int u,v;
            cin >> u >> v;
            merge(u,v);
        }
    }
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