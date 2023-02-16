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
vector<vector<int>>dp, cost;

void dnc(int i, int l, int r, int optl, int optr){
    if(l > r)return;
    pair<int,int>res = {1e18, 1};
    int mid = (l+r)/2;
    for(int j = max(0ll,optl);j<min(optr+101, mid);++j){
        res = min(res, make_pair(dp[i-1][j]+cost[j+1][mid],j));
    }
    dp[i][mid] = res.first;
    int opt = res.second;
    dnc(i, l, mid-1, min(optl,opt), opt);
    dnc(i, mid+1, r, opt, max(optr,opt));
}

void solve()
{
    cin >> n >> k;
    k++;
    dp = vector<vector<int>>(k+1, vector<int>(n+1,1e18));
    cost = vector<vector<int>>(n+1, vector<int>(n+1));
    vector<int>a(n+1),w(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=n;++i)cin >> w[i];

    // cost[i][j] = sum(i..j) * max(w[i..j])
    for(int i = 1;i<=n;++i){
        int sum = 0;
        int mx = -1e18;
        for(int j = i;j<=n;++j){
            sum+=a[j];
            mx = max(mx, w[j]);
            cost[i][j] = sum*mx;
        }
    }

    dp[0][0] = 0;
    for(int i = 1;i<=k;++i)dnc(i,1,n,0,n-1);
    cout << dp[k][n];
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