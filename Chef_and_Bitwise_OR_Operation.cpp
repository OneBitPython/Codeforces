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

const int N = 5001,K = 5001;
int dp[N][K],cost[N][N];

void dnc(int j, int l, int r, int optl, int optr){
    if(l > r)return;
    int m = (l+r)/2;
    pair<int,int>best = {0,0};
    for(int i = optl;i<min(m,optr+1);++i){
        best = max(best, {dp[i][j-1]+cost[i+1][m],i});
    }
    dp[m][j] = best.first;
    int opt = best.second;
    dnc(j,l,m-1,optl,opt);
    dnc(j,m+1,r,opt,optr);
}
void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i){
        cin >> a[i];
    }
    for(int i = 1;i<=n;++i){
        int c = 0;
        for(int j = i;j<=n;++j)c|=a[j],cost[i][j] = c;
    }
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=k;++j)dp[i][j]=0;
    }
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}