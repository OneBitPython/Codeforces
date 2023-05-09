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

vector<vector<int>>adj,tree,back,bb;
vector<int>par,visited,depth;
int n,m;
void dfs(int u, int p){
    visited[u] = 1;
    for(int v : adj[u]){
        if(v==p)continue;
        if(visited[v]==1)back[u].pb(v),bb[u].pb(v),bb[v].pb(u);
        else if(!visited[v]){
            par[v] = u;
            tree[u].pb(v);
            depth[v] = depth[u]+1;
            dfs(v,u);
        }
    }
    visited[u] = 2;
}
int ru = -1, rv = -1;
vector<pair<int,int>>res;
void dfs2(int u, int p){
    if(ru!=-1 && rv != -1)return;
    visited[u] = 1;
    int x = u;
    vector<int>take(n+1);
    int child = -1;
    int t= back[u].size();
    vector<pair<int,int>>rr;
    for(int i = t-1;i>=0;--i){
        int U = back[u][i];
        int befx = x, befchild = child;
        while(child!=U){
            int got = 0;
            rr.clear();
            for(int w : tree[x]){
                if(got==2)break;
                if(w!=child)got++,rr.pb({x,w});
            }
            if(got>=2){
                ru = U;
                rv = u;
                while(u!=U){
                    res.pb({par[u],u});
                    u = par[u];
                }
                for(auto x : rr)res.pb(x);
                return;
            }

            take[x] = 1;
            child = x;
            x = par[x];
        }
        x = befx;
        child = befchild;
        while(child!=U){
            int got = 0;
            int t = bb[x].size();
            rr.clear();

            for(int w = 0;w<min(4ll,t);++w){
                if(got==2)break;
                if(!take[bb[x][w]])got++,rr.pb({x,bb[x][w]});
            }
            if(got>=2){
                ru = U;
                rv = u;
                while(u!=U){
                    res.pb({par[u],u});
                    u = par[u];
                }
                for(auto x : rr)res.pb(x);

                return;
            }
            got = 0;
            rr.clear();
            for(int w = t-1;w>=max(0ll,t-4);--w){
                if(got==2)break;
                if(!take[bb[x][w]])got++,rr.pb({x, bb[x][w]});
            }
            if(got>=2){
                ru = U;
                rv = u;
                while(u!=U){
                    res.pb({par[u],u});
                    u = par[u];
                }
                for(auto x : rr)res.pb(x);
                return;
            }
            child = x;
            x = par[x];
        }
    }
    for(int v : tree[u]){
        if(v==p)continue;
        // go upwards from v till uand check if any of the nodes in the cycle follow the condition
        
        dfs2(v,u);
    }
}
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    tree = vector<vector<int>>(n+1);
    back = vector<vector<int>>(n+1);
    bb = vector<vector<int>>(n+1);
    visited = vector<int>(n+1);
    par = vector<int>(n+1); // par in dfs tree
    depth = vector<int>(n+1);
    ru = -1;
    rv = -1;
    res.clear();
    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1;i<=n;++i){
        if(!visited[i])dfs(i,-1);
    }
    for(int i =1;i<=n;++i){
        sort(all(bb[i]), [&](auto u, auto v){
            return depth[u] < depth[v];
        });
        sort(all(back[i]), [&](auto u, auto v){
            return depth[u] < depth[v];
        });
    }
    visited = vector<int>(n+1);
    for(int i = 1;i<=n;++i){
        if(ru!=-1 && rv !=-1)break;
        if(par[i]==0)dfs2(i,-1);
    }
    
    if(ru!=-1 && rv!=-1){
        cout << "YES" << endl;
        res.pb({ru, rv});
        cout << res.size() << endl;
        for(auto x : res)cout << x.first << ' ' << x.second << endl;
    }else cout << "NO" << endl;
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