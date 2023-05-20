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

int n;
vector<vector<int>>adj;
vector<int>dp;
map<vector<int>,int>code;
vector<int>taken;
int val = 0;
void dfs(int u, int p){
    vector<int>c;
    for(int  v: adj[u]){
        if(v==p)continue;
        dfs(v,u);
        c.pb(dp[v]);
    }
    sort(all(c));
    if(code.count(c))dp[u] = code[c];
    else{
        while(taken[val])val++;
        dp[u] = val;
        taken[val] = 1;
        code[c] = val;
    }
    
}

int symmetrical(int u, int p){
    map<int,int>cnt;
    for(int v : adj[u]){
        if(v==p)continue;
        cnt[dp[v]]++;
    }
    int odd = 0;
    for(auto x : cnt){
        if(x.second%2)odd++;
    }
    int sz = adj[u].size();
    if(u!=1)sz--;
    if((sz%2)==0){
        if(odd)return 0;
        return 1;
    }else{
        if(odd > 1)return 0;
        else{
            for(int v : adj[u]){
                if(cnt[dp[v]]%2 == 0)continue;
                return symmetrical(v,u); 
            }
            return 0;
        }
    }
}

void solve()
{
    cin >> n;
    adj = vector<vector<int>>(n+1);
    val = 0;
    code.clear();
    dp = vector<int>(n+1);
    taken = vector<int>(2*n+10);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    cout << (symmetrical(1,-1)?"YES":"NO") << endl;
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