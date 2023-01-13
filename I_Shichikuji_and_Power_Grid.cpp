#include <bits/stdc++.h>
using namespace std;

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

const int N = 2005;
int sz[N],id[N], c[N];
long long k[N];
vector<vector<long long>>edges;
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


void solve()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i].first >> a[i].second;

    for(int i = 1;i<=n;++i)cin >> c[i];
    for(int i = 1;i<=n;++i)cin>> k[i];

    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            if(i==j)continue;
            long long cost = (k[i]+k[j])*(abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second));
            edges.pb({cost,i,j});
        }
    }
    for(int i = 1;i<=n;++i)edges.pb({c[i], 0, i});
    for(int i = 0;i<=n;++i)id[i] = i, sz[i] = 1;
    long long res = 0;
    set<int>cities;
    sort(all(edges));
    vector<pair<int,int>>final;
    for(auto x : edges){
        if(merge(x[1], x[2])){
            if(x[1]==0)cities.insert(x[2]);
            if(x[1]!=0 && x[2]!=0)final.pb({x[1], x[2]});
            res+=x[0];
        }
    }

    cout << res << endl;
    cout << cities.size() << endl;
    for(auto x : cities)cout << x << ' ';
    cout << endl;
    cout << final.size() << endl;
    for(auto x : final)cout << x.first << ' ' << x.second << endl;
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