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
    int k;
    cin >> k;
    vector<vector<int>>a(26, vector<int>(26));
    int n = s.size();
    s = "0" + s;
    int q;
    cin >> q;
    while(q--){
        char u,v;
        cin >> u >> v;
        int c;
        cin >> c;
        a[u-'a'][v-'a'] = c;
    }
    vector<vector<vector<int>>>dp(n+5, vector<vector<int>>(k+5, vector<int>(26,-1e18)));
    for(int l = 0;l<26;++l){
        dp[1][1][l] = 0;
        if(l==(s[1]-'a'))dp[1][0][l]= 0;
    }
    int res = -1e18;
    for(int i = 2;i<=n;++i){
        dp[i][0][s[i]-'a'] = dp[i-1][0][s[i-1]-'a']+a[s[i-1]-'a'][s[i]-'a'];
        if(i==n)res = max(res, dp[n][0][s[i]-'a']);
    }
    for(int i = 2;i<=n;++i){
        // dp[i][j][k] cost uptill index i if we change j letters and we choose k as our ith letter
        for(int j = 1;j<=min(i,k);++j){
            for(int l = 0;l<26;++l){
                for(int m = 0;m<26;++m){
                    int need = (l!=(s[i]-'a'))+(m!=(s[i-1]-'a'));
                    if((i==2 && need !=j) || (j < need))continue;
                    if(l==(s[i]-'a')){
                        if(j <= (i-1))dp[i][j][l] = max(dp[i][j][l],dp[i-1][j][m]+a[m][l]);
                    }else{
                        dp[i][j][l] = max(dp[i][j][l],dp[i-1][j-1][m]+a[m][l]);
                    }
                }
                if(i==n)res = max(res, dp[i][j][l]);
            }
        }
    }
    cout << res;
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