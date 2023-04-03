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


int n,k;
const int N = 4001,K=801;
int cost[N][N],dp[N][K],a[N][N],pref[N][N];

void dnc(int j, int l, int r, int optl, int optr){
    if(l > r)return;
    int m = (l+r)/2;
    pair<int,int>best = {1e18,0};
    for(int i = optl;i<min(m,optr+1);++i){
        best = min(best, {dp[i][j-1]+cost[i+1][m],i});
    }
    dp[m][j] = best.first;
    int opt = best.second;
    dnc(j,l,m-1,optl,opt);
    dnc(j,m+1,r,opt,optr);
}

void solve()
{
    cin >> n >> k;
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=n;++j){
            if(j<K)dp[i][j]=1e9;
            a[i][j] = 0;
            pref[i][j]=0;
            cost[i][j]=0;
        }
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j)cin >> a[i][j],pref[i][j] = pref[i][j-1]+a[i][j];
    }
    for(int i = 1;i<=n;++i){
        cost[i][i] = 0;
        int c = 0;
        for(int j = i+1;j<=n;++j){
            c+=pref[j][j]-pref[j][i-1];
            cost[i][j] = c;
        }
    }
    // dp[i][j] = min cost till i if we form j groups
    dp[0][0] = 0;
    for(int j = 1;j<=k;++j)dnc(j,1,n,0,n-1);
    cout << dp[n][k] << endl;
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