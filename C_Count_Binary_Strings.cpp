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
vector<int>vis,color;

void dfs(int u, int c){
    color[u] = c;
    vis[u] = 1;
    for(int v : adj[u]){
        if(vis[v])continue;
        dfs(v,c);
    }
}

int mod = 998244353;
int ma(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int mm(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}

void solve()
{
    cin>> n;
    vector<vector<int>>a(n+1,vector<int>(n+1));
    vis.resize(n+1);
    adj.resize(n+1);
    color.resize(n+1);
    for(int i = 1;i<=n;++i){
        for(int j = i;j<=n;++j)cin >> a[i][j];
    }
    for(int i = 1;i<=n;++i){
        if(a[i][i] == 2){
            cout << 0 << endl;
            return;
        }
    }
    for(int i = 1;i<=n;++i){
        for(int j = i+1;j<=n;++j){
            if(a[i][j]==1){
                for(int k = i;k<j;++k)adj[k].pb(k+1);
            }
        }
    }
    int c = 1;
    for(int i = 1;i<=n;++i){
        if(!vis[i]){
            dfs(i,c);
            c++;
        }
    }
    for(int i = 1;i<=n;++i){
        if(color[i] == 0)color[i] = c++;
    }


    vector<vector<int>>dp(n+1, vector<int>(n+1));
    for(int i = 1;i<=n;++i){
        for(int j = i;j<=n;++j){
            if(a[i][j]!=2)continue;
            set<int>st;
            for(int k = i;k<=j;++k)st.insert(color[k]);
            if(st.size()<2){
                cout << 0 << endl;
                return;
            }
        }
    }
    dp[1][0] = 2;
    int res = 0;
    
    for(int i = 2;i<=n;++i){
        for(int j = i-2;j>=0;--j){
            bool ok = 1;
            for(int k = i;k>j;--k){
                if(a[k][i]==0)continue;
                if(a[k][i] == 2){
                    ok = 0;
                    break;
                }
            }
            for(int k = j;k>=1;--k){
                if(a[k][i]==0)continue;
                if(a[k][i]==1){
                    ok = 0;
                    break;
                }
            }
            if(!ok)continue;
            dp[i][j] = ma(dp[i][j],dp[i-1][j]);
        }
        bool ok = 1;
        for(int j = i-1;j>=0;--j){
            if(a[j][i]==1){
                ok = 0;
                break;
            }
        }
        if(!ok)continue;
        for(int j = i-2;j>=0;--j){
            bool ok = 1;
            for(int k = i-1;k>j;--k){
                if(a[k][i-1]==0)continue;
                if(a[k][i-1] == 2){
                    ok = 0;
                    break;
                }
            }
            for(int k = j;k>=1;--k){
                if(a[k][i-1]==0)continue;
                if(a[k][i-1]==1){
                    ok = 0;
                    break;
                }
            }
            if(!ok)continue;
            dp[i][i-1] = ma(dp[i][i-1],dp[i-1][j]);
        }
    }
    for(int j = n-1;j>=0;--j)res = ma(res, dp[n][j]);
    cout << res%mod;
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