#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
// #define endl "\n"

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

int n;
vector<vector<int>>adj;
vector<int>sub,par;
void comp(int u, int p){
    sub[u] = 1;
    for(int v : adj[u]){
        if(v==p)continue;
        par[v] = u;
        comp(v,u);

        sub[u]+=sub[v];
    }
}
vector<int>chainpos,chainleader;
void dfs(int u, int p, int pos, int leader){
    chainpos[u] = pos++;
    chainleader[u] = leader;
    int heavy = -1;
    for(int v : adj[u]){
        if(v==p)continue;
        if(sub[v] >= (sub[u]+1)/2)heavy = v;
    }
    if(heavy!=-1){
        dfs(heavy,u,pos,leader);
    }
    for(int v : adj[u]){
        if(v==p || v == heavy)continue;
        dfs(v,u,1,v);
    }
}

int q1(int u){
    cout << "d " << u << endl;
    int k;
    cin >> k;
    assert(k!=-1);
    return k;
}
int q2(int u){
    cout << "s " << u << endl;
    int k;
    cin >> k;
    assert(k!=-1);
    return k;
}
void solve()
{
    cin >> n;
    adj.resize(n+1);
    chainpos.resize(n+1);
    chainleader.resize(n+1);
    sub.resize(n+1);
    par.resize(n+1);
    for(int i= 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    comp(1,-1);
    dfs(1,-1,1,1);
    vector<int>sz(n+1),last(n+1);
    for(int i = 1;i<=n;++i)sz[chainleader[i]]++;
    for(int i= 1;i<=n;++i){
        if(chainpos[i] == sz[chainleader[i]])last[chainleader[i]] = i;
    }
    int d1 = q1(1);
    int curr = 1;
    while(1){
        int d2 = q1(last[curr]);
        if(d1==0){
            cout<< "! " << curr << endl;
            break;
        }
        if((d1+d2)==(sz[curr]-1)){
            // found solution
            int res = last[curr];
            for(int i= 1;i<=d2;++i)res = par[res];
            cout << "! " << res << endl;
            break;
        }
        int c2 = d2;
        int sec = last[curr];
        int bet = sz[curr]-1;
        while(sec!=par[curr]){
            if(bet+c2 == d1){
                int f = q2(sec);
                d1-=(bet+1);
                curr = f;
                break;
            }
            c2--;
            bet--;
            sec = par[sec];
        }

    }
}   

int32_t main()
{

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

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