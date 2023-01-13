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
int mxn = 3e5+1;
vector<int>fpf(mxn+1);
void pre(){
    for(int i = 2;i<=mxn;++i){
        if(fpf[i]==0){
            for(int j = i*i;j<=mxn;j+=i)fpf[j] = i;
        }
    }
}
set<int> fact(int x){
    set<int>f;
    while(x!=1){
        if(fpf[x]==0)fpf[x] = x;
        f.insert(fpf[x]);
        x/=fpf[x];

    }
    return f;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    set<int>st;
    for(int i = 1;i<=n;++i){
        set<int>s = fact(a[i]);
        for(auto x : s)st.insert(x);
    }
    int curr = n+1;
    vector<int>mp(mxn+1);
    for(auto x : st){
        mp[x] = curr;
        curr++;
    }
    vector<vector<int>>adj(curr+1);
    for(int i = 1;i<=n;++i){
        set<int>s = fact(a[i]);
        for(auto x : s){
            adj[i].pb(mp[x]);
            adj[mp[x]].pb(i);
        }
    }
    int u,v;
    cin >> u >> v;

    
    queue<int>q;
    vector<int>visited(curr+1);
    vector<int>par(curr+1,-1);
    q.push(u);
    bool ok = 0;
    while(!q.empty()){
        int u  = q.front();
        q.pop();
        if(visited[u])continue;
        if(u==v){
            ok = 1;
            break;
        }
        visited[u] = 1;
        for(int v : adj[u]){
            if(visited[v])continue;
            par[v] = u;
            q.push(v);
        }
    }
    if(!ok){
        cout << - 1 << endl;
        return;
    }
    int val = v;
    vector<int>res;
    while(val!=u){
        if(val<=n)res.pb(val);
        if(val==-1){
            cout << -1 << endl;
            return;
        }
        val = par[val];
    }
    res.pb(u);
    reverse(all(res));
    cout << res.size() << endl;
    for(auto x : res)cout << x << ' ';
    cout << endl;
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
    pre();
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}