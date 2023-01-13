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


vector<vector<int>>adj;
vector<int>par;
void dfs(int u, int p){
    for(int v : adj[u]){
        if(v==p)continue;
        par[v] = u;
        dfs(v,u);
    }
}
const int sz = 1e5;
struct lichao{
    struct line{
        int m,c;
        int f(int x){
            return m*x+c;
        }
    };
    vector<line>seg;
    vector<int>left,right;
    int sz = 1;
    int node = 0;
    lichao(int n){
        sz = n;
        seg.pb({0,1000000000});
        right.pb(-1);
        left.pb(-1);
    }
 
    int get_next(){
        node++;
        seg.pb({0,1000000000});
        right.pb(-1);
        left.pb(-1);
        return node;
    }
    void insert(int x, int lx, int rx, line l){
        int m = (lx+rx)/2;
        bool mid = l.f(m) < seg[x].f(m);
        bool le = l.f(lx) < seg[x].f(lx);
        if(mid)swap(seg[x], l);
 
        if(left[x]==-1)left[x] = get_next();
        if(right[x]==-1)right[x] = get_next();
 
        if(rx-lx==1)return;
        if(le!=mid)insert(left[x], lx, m, l);
        else insert(right[x],  m, rx, l);
    }
 
    void insert(int m, int c){
        insert(0,0,sz,{m,c});
    }
 
    int query(int x, int lx, int rx, int q){
        if(rx-lx==1)return seg[x].f(q);
        int m = (lx+rx)/2;
 
        if(left[x]==-1)left[x] = get_next();
        if(right[x]==-1)right[x] = get_next();
 
        if(q < m)return min(seg[x].f(q), query(left[x], lx, m, q));
        else return min(seg[x].f(q), query(right[x], m, rx, q));
    }
 
    int query(int x){
        return query(0,0,sz,x);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1), b(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=n;++i)cin >> b[i];
    adj.resize(n+1);
    par.resize(n+1);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    /*
    dp[i] = dp[j] + (a[i]*b[j])
    c - dp[j]
    x - a[i]
    m - b[j]
    */
    vector<int>in(n+1);
    in[1] = adj[1].size();
    queue<int>q;
    vector<int>visited(n+1);

    lichao cht(sz);

    vector<int>dp(n+1);
    for(int i = 2;i<=n;++i){
        in[i] = adj[i].size()-1;
        if(in[i]==0){
            q.push(i);
            cht.insert(b[i], 0);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        int v = par[u];
        in[v]--;
        if(in[v]==0){
            q.push(v);
            dp[v] = cht.query(a[v]);
            cht.insert(b[v], dp[v]);
        }
    }
    for(int i = 1;i<=n;++i)cout << dp[i] << ' ';
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