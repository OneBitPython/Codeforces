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
    int m;
    cin >> m;
    vector<vector<set<pair<int,int>>>>dp(n+1, vector<set<pair<int,int>>>(m+1));
    s = "0" + s;
    // dp[i][j][k] max possition till position i if you make j changes and you are facing (k==1positive x direction) (k==0 negative x direction)
    // at the start you are facing positive x
    dp[0][0].insert({0,0});
    for(int i = 1;i<=n;++i){
        if(s[i] ==  'T'){
            for(auto x :dp[i-1][0]){
                dp[i][0].insert({-x.second,-x.first});
            }
        }else{
            for(auto x : dp[i-1][0]){
                dp[i][0].insert({x.first+1,x.second+1});
            }
        }
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            for(int k = 0;k<=j;++k){
                // you are changing the s[i]th operation k times
                char op = s[i];
                if(i==1 && k!=j)continue;
                if(k%2)op = (op=='T'?'F':'T');
                if(op == 'T'){
                    for(auto x : dp[i-1][j-k]){
                        dp[i][j].insert({-x.second,-x.first});
                    }
                }else{
                    for(auto x : dp[i-1][j-k]){
                        dp[i][j].insert({x.first+1,x.second+1});
                    }
                }
            }
        }
    }
    int res = 0;
    for(auto x : dp[n][m])res = max({res, abs(x.first),abs(x.second)});
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