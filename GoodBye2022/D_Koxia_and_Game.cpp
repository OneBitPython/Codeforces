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


vector<int>id,sz,edges,self;
int root(int x){
    if(x==id[x])return x;
    return id[x] = root(id[x]);
}

void merge(int u, int v){
    u = root(u);
    v  = root(v);
    if(u==v)return;
    id[v] = u;
    sz[u]+=sz[v];
    edges[u]+=edges[v];
    self[u]|=self[v];   
}

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    for(int i = 0;i<n;++i)cin >> a[i];
    for(int i = 0;i<n;++i)cin >> b[i];
    id = vector<int>(n+1), 
    sz = vector<int>(n+1,1);
    edges.resize(n+1);
    iota(all(id),0ll);
    int ans = 1;
    int mod = 998244353;
    
    self.resize(n+1);
    for(int i = 0;i<n;++i){
        merge(a[i],b[i]);
        edges[root(a[i])]++;
        if(a[i]==b[i])self[root(a[i])] = 1;
    }
    vector<int>taken(n+1);
    for(int i = 1;i<=n;++i){
        if(taken[root(i)])continue;
        int x = root(i);
        taken[x] = 1;
        if(edges[x]!=sz[x])ans = 0;
        if(self[x]){
            ans*=n;
            ans%=mod;
            continue;
        }
        ans*=2, ans%=mod;
    }
    cout << ans << endl;
    
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