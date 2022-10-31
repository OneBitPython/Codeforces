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
    string s;
    cin >> s;
    int n = s.size();
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)a[i] = (s[i-1]-'0');
    vector<int>dp(n+1); // dp[i] max number of segments divisible by 3 uptill i
    // you can find the greatest j < i such that the segment j->i is divisible by 3 or you can continuoe of i-1
    // so dp[i] = max(dp[j]+1,dp[i-1])
    vector<int>pref(n+1);
    vector<vector<int>>b(4);
    b[0].pb(0);
    for(int i = 1;i<=n;++i){
        pref[i] = pref[i-1]+a[i];
        pref[i]%=3;
        int req = pref[i];
        if(!b[req].empty()){
            dp[i] = max(dp[i-1],dp[b[req].back()]+1);
        }
        dp[i] = max(dp[i],dp[i-1]);
        b[pref[i]].pb(i);
    }
    cout << dp[n] << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}