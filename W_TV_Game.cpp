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
    string s;
    cin >> s;
    s = "0" + s;
    int m = n*2;
    vector<vector<pair<double,string>>>dp(m+1, vector<pair<double,string>>(n+1));
    for(int i = 1;i<=m;++i){
        // add s[i] to the first score
        for(int j = 0;j<=min(i,n);++j){
            int k = i-j;
            if(k > n)continue;

            double c1 = 0, c2 = 0;
            bool ok1 = 0, ok2 = 0;
            if(j>0){
                c1 = dp[i-1][j-1].first + (pow(10,n-j)*(s[i]-'0'));
                ok1 = 1;
            }
            if(k > 0){
                ok2 = 1;
                c2 = dp[i-1][j].first+(pow(10,n-k)*(s[i]-'0'));
            }
            if(ok1 && ok2){
                if(c1 > c2)dp[i][j] = {c1,dp[i-1][j-1].second+"H"};
                else dp[i][j] = {c2, dp[i-1][j].second+"M"};
            }else if(ok1){
                dp[i][j] = {c1,dp[i-1][j-1].second+"H"};
            }else{
                dp[i][j] = {c2, dp[i-1][j].second+"M"};
            }
        }
    }  
    cout << (dp[m][n].second);

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