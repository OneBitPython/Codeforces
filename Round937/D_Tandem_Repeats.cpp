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
    s = "0"+s;
    map<char,vector<int>>pos;
    for(int i = 1;i<=n;++i)pos[s[i]].pb(i);
    vector<int>dp(n+1);
    for(auto x : pos[s[1]]){
        if(x!=1)dp[x] = 1;
    }
    for(auto x : pos['?']){
        if(x!=1)dp[x]  = 1;
    }
    if(s[1]=='?'){
        for(int j = 2;j<=n;++j)dp[j] = 1;
    }
    int res = 0;
    for(int i = 1;i<n;++i){
        if(s[i]==s[i+1] || s[i]=='?' || s[i+1]=='?')res = 2;
    }
    for(int i = 2;i<=n;++i){
        vector<int>dp2(n+1);
        if(s[i]=='?'){
            for(int x = i+1;x<=n;++x){
                if(x==(i+1))dp2[x] = 1;
                else dp2[x] = dp[x-1]+1;
                if((x-dp2[x])==i)res = max(res, dp2[x]*2);
            }
            dp = dp2;
            continue;
        }
        for(int j = (int)(pos[s[i]].size())-1;j>=0;--j){
            int x = pos[s[i]][j];
            if(x <= i)break;
            if(x==(i+1))dp2[x] = 1;
            else dp2[x] = dp[x-1]+1;
            if(x-dp2[x] == i)res = max(res, dp2[x]*2);
        }
        for(int j = (int)(pos['?'].size())-1;j>=0;--j){
            int x = pos['?'][j];
            if(x <= i)break;
            if(x==(i+1))dp2[x] = 1;
            else dp2[x] = dp[x-1]+1;
            if(x-dp2[x] == i)res = max(res, dp2[x]*2);
        }

        dp = dp2;
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