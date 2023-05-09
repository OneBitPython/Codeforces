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

vector<int>id,sz,ans,ad,came;

/*
ans - the current answer for node i till most recently updtaed
ad[i] - the update that is supposed to be carried out in the set of node i
came[i] - the update that was supposed to be carried out in the parent set of node i when it was merged with that set
*/
vector<set<int>>dp;
int root(int x){
    if(id[x]==x)return x;
    return id[x] = root(id[x]);
}
void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return;
    if(sz[v] > sz[u])swap(u,v);
    for(auto x : dp[v]){
        ans[x] += ad[root(x)];
        ans[x] -= came[x];
        came[x] = ad[u];
        dp[u].insert(x);
    }   
    dp[v].clear();
    id[v] = u;
    sz[u]+=sz[v];
}
void add(int u, int x){
    u = root(u);
    ad[u]+=x;
}
int give(int u){
    return ans[u]+ad[root(u)]-came[u];
}
void solve()
{
    int n,k;
    cin>> n >> k;
    dp.resize(n+1);
    id.resize(n+1);
    sz.resize(n+1,1);
    ans.resize(n+1);
    ad.resize(n+1);
    came.resize(n+1);
    iota(all(id),0ll);
    for(int i = 1;i<=n;++i)dp[i].insert(i);
    while(k--){
        string s;
        cin >> s;
        if(s=="get"){
            int u;
            cin >> u;
            cout << give(u) << endl;
        }else if(s=="add"){
            int u,x;
            cin >>u >> x;
            add(u,x);
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