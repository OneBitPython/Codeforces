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



void solve()
{
    int n,x,y;
    cin >> n >> x >> y;
    string s,t;
    cin >> s >> t;
    s = "0"+s;
    t = "0"+t;

    int cnt = 0;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)a[i] = (s[i]!=t[i]),cnt+=a[i];
    if(cnt%2){
        cout << -1 << endl;
        return;
    }
    vector<int>c = {0};
    for(int i = 1;i<=n;++i){
        if(a[i])c.pb(i);
    }
    if(y < x){
        if(cnt == 2){
            if((c[1])!=(c[2]-1)){
                cout << y << endl;
                return;
            }
            cout << min(x, y*2) << endl;
            return;
        }
        cout << y * (cnt/2) << endl;
        return;
    }
    // always optimal to pair 1s in group of twos
    // you can't make groups intersect
    // you never want a gruop to be a subset of another
    // you'd take only adjacent ones
    vector<vector<int>>dp(n+1, vector<int>(cnt/2 + 1,1e18)); // dp[i][j] minimum cost to form j groups uptill i (a group is 2 adjacent 1s)
    int ptr = 0;
    dp[0][0] = 0;
    for(int i = 1;i<=n;++i){
        if(c[ptr+1]==i)ptr++;
        // ptr stores who we are going to be pairing this guy with
        for(int j = 0;j<=(cnt/2);++j){
            dp[i][j] = dp[i-1][j];
            if(!a[i])continue;
            if(ptr > 1 && j){
                // pair i with c[ptr]
                dp[i][j] = min(dp[i][j],dp[c[ptr-1]-1][j-1]+(i-c[ptr-1])*x);
            }
        }
    }
    int res = 1e18;
    for(int j = 0;j<=(cnt/2);++j){
        res = min(res, dp[n][j]+((cnt-2*j)/2) * y);
    }
    cout << res << endl;
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