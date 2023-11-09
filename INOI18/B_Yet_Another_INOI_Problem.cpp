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

const int mxn = 5001;
vector<pair<int,int>> adj[mxn],rev[mxn];
vector<int>pref;
vector<vector<int>>dp;
int cost(int l, int r){
    return (r-l)*(pref[r]-pref[l-1]);
}
void dnc(int i, int l, int r, int optl, int optr){
    if(l > r)return;
    pair<int,int>res = {1e18, 1};
    int mid = (l+r)/2;
    for(int j = optl;j<min(optr+1, mid);++j){
        res = min(res, make_pair(dp[j][1^i]+cost(j+1,mid),j));
    }
    dp[mid][i] = res.first;
    int opt = res.second;
    dnc(i, l, mid-1, optl, opt);
    dnc(i, mid+1, r, opt, optr);
}

void solve()
{
    int n,q,p,m; // p = number of problems
    cin >> n >> q >> p >>  m;
    pref.resize(q+1);
    for(int i = 1;i<=m;++i){
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w});
        rev[v].pb({u,w});
    }
    vector<int>forw(n+1,1e18); // forw stores shortest path from i->q+1 (i <= q)
    vector<int>back(n+1,1e18); // back stores shortest path from q+1 -> i (i <= q)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,q+1});
    forw[q+1] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d!=forw[u])continue;
        for(auto &[v,w] : rev[u]){
            int curr_dist = forw[v], new_dist = forw[u]+w;
            if(new_dist < curr_dist){
                forw[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
    pq.push({0,q+1});
    back[q+1] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d!=back[u])continue;
        for(auto &[v,w] : adj[u]){
            int curr_dist = back[v], new_dist = back[u]+w;
            if(new_dist < curr_dist){
                back[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
    vector<int>a(q+1);
    for(int i = 1;i<=q;++i)a[i] = forw[i] + back[i];
    sort(all(a));
    for(int i = 1;i<=q;++i)pref[i] = pref[i-1]+a[i];
    dp = vector<vector<int>>(q+1, vector<int>(2));

    for(int i = 1;i<=q;++i)dp[i][0] = 1e18;
    for(int i = 1;i<=p;++i)dnc(i%2,1,q,0,q-1);
    cout << dp[q][p%2] << endl;
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