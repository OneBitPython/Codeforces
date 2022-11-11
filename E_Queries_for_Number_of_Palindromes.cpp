#include <bits/stdc++.h>
using namespace std;

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


const int N = 5001;
int dp[N][N], pal[N][N];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    // dp[l][r] number of palindromic substrings between l and r (inclusive)
    for(int i = 0;i<n;++i)dp[i][i] = 1,pal[i][i] = 1;
    for(int i = 0;i<n-1;++i){
        dp[i][i+1] = 2;

        if(s[i] == s[i+1])dp[i][i+1]++;
        if(s[i] == s[i+1])pal[i][i+1] = 1;
    }
    for(int gap = 3;gap<=n;++gap){
        for(int i = 0;i<n;++i){
            if(i+gap-1 >= n)break;
            int j = i+gap-1;
            dp[i][j] = dp[i][j-1]-dp[i+1][j-1]+dp[i+1][j];
            if(pal[i+1][j-1] && s[i] == s[j]){
                pal[i][j] = 1;
            }
            dp[i][j] += pal[i][j];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << dp[l-1][r-1] << endl;
    }
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