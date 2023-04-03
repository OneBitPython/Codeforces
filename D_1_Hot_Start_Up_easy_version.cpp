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

const int N = 5001,K=5001;
int dp[2][K][K];
int cold[K],hot[K],a[N],cnt[K];

void solve()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=k;++i)cin >> cold[i];
    for(int i = 1;i<=k;++i)cin >> hot[i];
    for(int i = 0;i<=1;++i){
        for(int j = 0;j<=k;++j){
            for(int l = 0;l<=k;++l)dp[i][j][l] = 1e18;
        }
    }
    for(int i = 0;i<=k;++i)cnt[i]=0;

    dp[1][a[1]][0] = cold[a[1]];
    dp[1][0][a[1]] = cold[a[1]];

    
    cnt[a[1]] = 1;
    vector<vector<pair<int,int>>>vis(2);
    vis[1].pb({a[1],0});
    vis[1].pb({0,a[1]});
    for(int i = 2;i<=n;++i){
        int c = i%2, p = c^1;
        int x = 0; // x = first value != a[i]
        vis[c].clear();
        cnt[a[i]]++;


        for(int j = i-1;j>=1;--j){
            if(a[j]!=a[i] && x==0)x = a[j];
        }
        dp[c][a[i]][a[i-1]] = 1e18;
        dp[c][a[i-1]][a[i]] = 1e18;

        for(int y = i-2;y>=0;--y){
            dp[c][a[i]][a[i-1]] = min(dp[c][a[i]][a[i-1]],dp[p][a[y]][a[i-1]]+cold[a[i]]);
            dp[c][a[i-1]][a[i]] = min(dp[c][a[i-1]][a[i]], dp[p][a[i-1]][a[y]]+cold[a[i]]);

            int w = cold[a[i]];
            if(a[i]==a[i-1])w = hot[a[i]];
            dp[c][a[i]][a[y]] = min(dp[c][a[i]][a[y]],dp[p][a[i-1]][a[y]]+w);
            dp[c][a[y]][a[i]] = min(dp[c][a[y]][a[i]],dp[p][a[y]][a[i-1]]+w);

            vis[c].pb({a[i],a[i-1]});
            vis[c].pb({a[i-1],a[i]});
            vis[c].pb({a[i],a[y]});
            vis[c].pb({a[y],a[i]});
        }
        

        if(cnt[a[i]]>1){
            dp[c][a[i]][x] = min(dp[c][a[i]][x],dp[p][a[i]][x]+hot[a[i]]);
            dp[c][x][a[i]] = min(dp[c][x][a[i]],dp[p][x][a[i]]+hot[a[i]]);
            vis[c].pb({a[i],x});
            vis[c].pb({x,a[i]});
        }

        if(i==n){
            int mn = 1e18;
            for(int y = i-1;y>=0;--y){
                mn = min(mn,dp[c][a[i]][a[y]]);
            }
            cout << mn << endl;
        }
        for(auto x : vis[p])dp[p][x.first][x.second]=1e18;

    }
    if(n==1)cout << cold[a[1]] << endl;
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