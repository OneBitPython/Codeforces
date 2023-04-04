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
int dp[N][2],cost[N][N];
struct node{
    int x=0,w=0;
};
vector<int>pref;
int sum(int l, int r){
    return pref[r]-pref[l-1];
}
void dnc(int j, int l, int r, int optl, int optr){
    if(l > r)return;
    int m = (l+r)/2;
    pair<int,int>best = {1e18,0};
    for(int i = optl;i<min(m,optr+1);++i){
        best = min(best, {dp[i][j^1]+cost[i+1][m],i});
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
    vector<node>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i].x >> a[i].w;
    // optimal splitting point for a range [l,r] is the first position where sumw[l..i] >= sumw[i+1..r]
    pref.resize(n+1);
    for(int i = 1;i<=n;++i)pref[i] = pref[i-1]+a[i].w;
    for(int i = 1;i<=n;++i){
        int res = 0;
        int p = i; // position of split
        for(int j = i+1;j<=n;++j){
            res+=(a[j].x-a[p].x)*a[j].w;
            while(p < j && sum(i,p)<sum(p+1,j)){
                res-=(a[p+1].x-a[p].x)*sum(p+1,j);
                p++;
                res+=(a[p].x-a[p-1].x)*sum(i,p-1);
            }
            cost[i][j] = res;
        }
    }
    for(int i = 0;i<=n;++i){
        dp[i][0] = 1e18;
        dp[i][1] = 1e18;
    }
    dp[0][0] = 0;
    for(int j = 1;j<=k;++j){
        for(int i = 0;i<=n;++i)dp[i][j%2]=1e18;
        dnc(j%2,1,n,0,n-1);
    }
    cout << dp[n][k%2] << endl;
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