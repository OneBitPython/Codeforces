#include <bits/stdc++.h>
using namespace std;

#define int long long
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

vector<vector<int>>adj;


int query(int u, int v){
    cout << "? " << u << ' ' << v << endl;
    int k;
    cin >> k;
    return k;
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    vector<int>in(n+1);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        in[u]++;
        in[v]++;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    set<int>opt;
    for(int i = 1;i<=n;++i){
        if(in[i]==1)opt.insert(i);
    }
    while(opt.size()>1){
        int u = *opt.begin();
        opt.erase(opt.begin());
        int v=*opt.begin();
        opt.erase(opt.begin());

        int k = query(u,v);
        if(k==u || k==v){
            cout << "! " << k << endl;
            return;
        }
        if(k!=u && k!=v){
            for(auto x : adj[u]){
                in[x]--;
                if(in[x]==1)opt.insert(x);
            }
            for(auto x :adj[v]){
                in[x]--;
                if(in[x]==1)opt.insert(x);
            }
        }
    }
    cout << "! " << *opt.begin();
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
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