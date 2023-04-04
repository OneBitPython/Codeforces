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

const int N = 35001,K = 51;
int dp[N][K];
vector<int>a;
void add(int x, int &res, vector<int>&cnt){
    cnt[x]++;
    res+=(cnt[x]==1);
}
void remove(int x, int &res, vector<int>&cnt){
    cnt[x]--;
    res-=(cnt[x]==0);
}
void dnc(int j, int l, int r, int optl, int optr, int parent, int res, vector<int>&cnt){
    if(l > r)return;
    int m = (l+r)/2;

    if(parent!=-1){
        if(parent > m){
            for(int i = m+1;i<=parent;++i)remove(a[i],res,cnt);
        }else{
            for(int i = parent+1;i<=m;++i)add(a[i],res,cnt);
        }
    }
    pair<int,int>best = {0,0};
    for(int i = optl;i<min(m,optr+1);++i){
        remove(a[i],res,cnt);
        best = max(best, {dp[i][j-1]+res,i});
    }
    for(int i = optl;i<min(m,optr+1);++i)add(a[i],res,cnt);
    dp[m][j] = best.first;
    int opt = best.second;
    dnc(j,l,m-1,optl,opt,m,res,cnt);

    for(int i = optl;i<opt;++i)remove(a[i],res,cnt);
    dnc(j,m+1,r,opt,optr,m,res,cnt);
    for(int i = optl;i<opt;++i)add(a[i],res,cnt);

    if(parent > m){
        for(int i = m+1;i<=parent;++i)add(a[i],res,cnt);
    }else{
        for(int i = parent+1;i<=m;++i)remove(a[i],res,cnt);
    }
}
void solve()
{
    int n,k;
    cin >> n >> k;
    a.resize(n+1);
    for(int i = 1;i<=n;++i){
        cin >> a[i];
    }
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=k;++j)dp[i][j]=0;
    }
    dp[0][0] = 0;
    vector<int>cnt(n+1);
    for(int j = 1;j<=k;++j){
        cnt = vector<int>(n+1);
        int res = 0;
        for(int i = 0;i<=(n+1)/2;++i)add(a[i],res,cnt);
        dnc(j,1,n,0,n-1,-1,res,cnt);
    }
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