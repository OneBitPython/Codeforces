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

const int mxn = 1e5+1;
int val[mxn],pres[mxn];

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>queries;
    vector<int>a(n+1), conf(n+1);
    for(int i = 1;i<=m;++i){
        int u,v,c;
        cin >>u >> v >> c;
        if(u==v){
            conf[u] = 1;
            a[u] = c;
            continue;
        }
        queries.pb({u, v, c});
    }
    vector<vector<pair<int,int>>>adj(n+1);
    for(int j = 0;j<=30;++j){
        for(int i = 1;i<=n;++i){
            adj[i].clear();
            val[i] = 1;
            pres[i] = 0;
        }

        for(auto x: queries){
            int w = 0;
            if(x[2]&(1ll<<j)) w= 1;
            adj[x[0]].pb({x[1], w});
            adj[x[1]].pb({x[0], w});
            pres[x[0]] = 1;
            pres[x[1]] = 1;
        }
        for(int i =1;i<=n;++i){
            if(conf[i]){
                bool w = (a[i]&(1ll<<j));
                val[i] = w;
            }
            for(auto &[v,w] : adj[i]){
                pres[i] = 1;
                if(w==0){
                    val[i] = 0;
                    val[v] = 0;
                }
            }
        }
        for(int i =1;i<=n;++i){
            if(!val[i])continue;
            if(conf[i]){
                bool w = (a[i]&(1ll<<j));
                val[i] = w;
                continue;
            }
            bool ok = 1;
            for(auto &[v,w] : adj[i]){
                
                if(w==1 && !val[v]){
                    ok = 0;
                }
            }
            if(ok)val[i] = 0;
        }
        for(int i =1;i<=n;++i){
            if(pres[i] && !conf[i])a[i]+=((val[i])*(1ll<<j));
        }
    }
    for(int i = 1;i<=n;++i)cout << a[i] << ' ';
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