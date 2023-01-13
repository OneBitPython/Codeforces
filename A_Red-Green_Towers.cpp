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
    int g,r;
    cin >> r >> g;
    int tot = g+r;
    int h = 0;
    for(int i = 1;i<=tot;++i){
        if((i*(i+1))/2 <= tot)h = i;
        else break;
    }
    vector<vector<int>>dp(2, vector<int>(g+1));
    dp[0][0] = 1;
    int mod = 1e9+7;
    int res = 0;
    for(int i = 1;i<=h;++i){
        int c = i%2;
        int p = 1-c;
        for(int j = 0;j<=g;++j){
            dp[c][j] = 0;
            int req = (i*(i+1))/2;
            req-=j;
            if(i<=j){
                // use green
                dp[c][j]+=dp[p][j-i];
                dp[c][j]%=mod;
            }
            if(r>=req){
                dp[c][j]+=dp[p][j];
                dp[c][j]%=mod;
            }
            if(i==h){
                res+=dp[c][j];
                res%=mod;
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