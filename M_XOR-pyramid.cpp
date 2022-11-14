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
    vector<vector<int>>dp(n+1, vector<int>(n+1));
    for(int i = 0;i<n;++i){
        int v;
        cin >> v;
        dp[0][i] = v;
    }
    for(int i = 1;i<n;++i){
        for(int j = 0;j<n-i;++j){
            dp[i][j] = dp[i-1][j]^dp[i-1][j+1];
        }
    }
    vector<vector<int>>res(n,vector<int>(n));
    for(int gap = 1;gap<=n;++gap){
        for(int i = 0;i<n;++i){
            int j = i+gap-1;
            if(j >= n)break;
            if(gap == 1){
                res[i][i] = dp[0][i];
                continue;
            }
            res[i][j] = dp[gap-1][i];
            
            res[i][j] = max({res[i+1][j], res[i][j-1],res[i][j]});
            if(gap > 2)res[i][j] =max(res[i][j],res[i+1][j-1]);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        --l;
        --r;
        cout << res[l][r] << endl;
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