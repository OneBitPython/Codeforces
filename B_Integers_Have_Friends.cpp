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

int mxn = 3e5;
vector<int>lg(mxn+1);
void pre(){
    for(int i = 1;i<=mxn;++i)lg[i] = log2(i);
}
int query(vector<vector<int>>&dp, int l, int r){
    int lo = lg[r-l+1];
    return __gcd(dp[l][lo],dp[r-(1ll<<lo)+1][lo]);
}

void solve()
{
    int n;
    cin >>n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    vector<int>b;
    for(int i = 0;i<n-1;++i)b.pb(abs(a[i]-a[i+1]));
    
    n = b.size();
    vector<vector<int>>dp(n, vector<int>(30));
    for(int i = 0;i<n;++i)dp[i][0] = b[i];
    for(int j=1;j<30;++j){
        for(int i = 0;i+(1ll<<j)<=n;++i){
            dp[i][j] = __gcd(dp[i][j-1],dp[i+(1ll<<(j-1))][j-1]);
        }
    }

    int res = 1;
    for(int i = 0;i<n;++i){
        int l = i, r = n;
        while(l+1 < r){
            int m = (l+r)/2;
            int g = query(dp,i,m);
            if(g>1)l = m;
            else r= m;
        }
        if(query(dp,i,l)==1)continue;
        res = max(res, l-i+2);
    }
    cout <<res << endl;
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
    pre();
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}