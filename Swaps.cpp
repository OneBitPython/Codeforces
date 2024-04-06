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
    int n;
    cin >> n;
    int c = n;
    n = (1ll<<n);
    vector<int>a(n+1);
    for(int i =1;i<=n;++i)cin >> a[i];
    int q;
    cin >> q;
    vector<pair<int,int>>dp(c+1);
    for(int k = 1;k<=c;++k){
        int im = (1ll<<k);
        int fr = 0, sr = 0;
        for(int i = 1;i<=n;i+=im){
            for(int j = i;j<i+(im/2);++j)fr+=a[j];
            for(int j = i+(im/2);j<(i+im);++j)sr+=a[j];
        }
        dp[k] = {fr,sr};
    }
    vector<int>pp(c+1);
    pp[0] = 1;
    for(int i = 1;i<=c;++i)pp[i] = pp[i-1]*2;
    while(q--){
        int i,v;cin >> i >> v;i++;
        // make update TODO
        int change = v - a[i];
        a[i] = v;
        for(int k =1;k<=c;++k){
            if(((i-1)>>(k-1))&1)dp[k].second += change;
            else dp[k].first += change;
        }
        int res = 0;
        for(int k = 1;k<=c;++k)res+=(min(dp[k].first,dp[k].second)*pp[k-1]);
        cout << res << endl;
    }
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