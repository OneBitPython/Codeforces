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

vector<vector<int>>dp;
vector<int>pre;
int sol(int l, int r){
    int L = pre[r-l+1];
    return __gcd(dp[l][L],dp[r-(1ll<<L)+1][L]);
}

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    pre.resize(n+1);
    for(int i = 1;i<=n;++i){
        pre[i] = log2(i);
    }
    for(int i = 1;i<=n;++i)cin >> a[i];
    dp = vector<vector<int>>(n+1, vector<int>(21));
    for(int j = 0;j<=20;++j){
        for(int i = 1;i+(1ll<<j)-1 <= n;++i){
            if(j==0){
                dp[i][j] = a[i];
                continue;
            }
            dp[i][j] = __gcd(dp[i][j-1],dp[i+(1ll<<(j-1))][j-1]);
        }
    }
    int res = 0;
    int bef = 0;
    for(int i =  1;i<=n;++i){
        if(a[i]==1){
            res++;
            bef = i;
            cout<<res << ' ';
            continue;
        }
        int l = bef+1, r = i;
        int ans = -1;
        while(l <= r){
            int m = (l+r)/2;
            int x = sol(m,i);
            if(x==(i-m+1)){
                ans = m;
                break;
            }else if(x > (i-m+1))r = m-1;
            else l = m+1;
        }
        if(ans != -1)bef = i,res++;
        cout << res << ' ';
    }
    cout << endl;
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