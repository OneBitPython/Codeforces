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

const int N = 1e5+1, K = 21;
int dp[N][K];
vector<int>cnt,a;
void add(int x, int &res,vector<int>&cnt){
    res-=(cnt[x]*(cnt[x]-1))/2;
    cnt[x]++;
    res+=(cnt[x]*(cnt[x]-1))/2;
}
void remove(int x, int &res,vector<int>&cnt){
    res-=(cnt[x]*(cnt[x]-1))/2;
    cnt[x]--;
    res+=(cnt[x]*(cnt[x]-1))/2;
}

void dnc(int j, int l, int r, int optl, int optr, int parent, vector<int>&cnt, int res){
    // the cost from [optl,parentm] has been computed
    // subtract the cost from [m+1,parentm] if moved left
    // add the cost from [praentm+1,m] if right
    if(l > r)return;
    int m = (l+r)/2;
    if(parent!=-1){
        if(parent > m){
            for(int i = m+1;i<=parent;++i)remove(a[i],res,cnt);
        }else{
            for(int i = parent+1;i<=m;++i)add(a[i],res,cnt);
        }
    }
    pair<int,int>best = {1e18,0};
    for(int i = optl;i<min(optr+1,m);++i){
        remove(a[i],res,cnt);
        best = min(best, {dp[i][j-1]+res,i});
    }
    for(int i = optl;i<min(optr+1,m);++i)add(a[i],res,cnt);
    // optl to m-1 has been computed
    int opt = best.second;
    dp[m][j] = best.first;

    dnc(j,l,m-1,optl,opt,m,cnt,res);
    // delete [optl,opt-1]
    for(int i = optl;i<min(m,opt);++i)remove(a[i],res,cnt);
    dnc(j,m+1,r,opt,optr,m,cnt,res);
    for(int i = optl;i<min(m,opt);++i)add(a[i],res,cnt);
    if(parent!=-1){
        if(parent>m){
            for(int i = m+1;i<=parent;++i)add(a[i],res,cnt);
        }else{
            for(int i = parent+1;i<=m;++i)remove(a[i],res,cnt);
        }
    }

}

void solve()
{
    int n,k;
    cin >> n >> k;
    cnt.resize(n+1);
    a.resize(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i= 0;i<=n;++i){
        for(int j = 0;j<=k;++j)dp[i][j] = 1e18;
    }
    dp[0][0] = 0;
    for(int j = 1;j<=k;++j){
        int res = 0;
        cnt = vector<int>(n+1);
        for(int i = 0;i<=(1+n)/2;++i)add(a[i],res,cnt);
        dnc(j,1,n,0,n-1,-1,cnt,res);
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