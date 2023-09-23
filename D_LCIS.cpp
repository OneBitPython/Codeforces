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
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    int m;
    cin >> m;
    vector<int>b(m+1);
    for(int i = 1;i<=m;++i)cin >> b[i];
    vector<int>res(n+1);
    vector<vector<int>>dp(n+1, vector<int>(m+1)),ref(n+1,vector<int>(m+1)); // ref[i][j] stores the last index k < j such that b[k] = a[i]
    for(int i = 1;i<=n;++i){
        int idx = 0;
        for(int j = 1;j<=m;++j){
            if(a[i]==b[j])dp[i][j] = 1;
            ref[i][j] = idx;
            if(b[j]==a[i])idx = j;
        }
    }
    int mx = 0,pos = 0;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            if(a[i]!=b[j])continue;
            for(int k = i-1;k>=1;--k){
                if(a[k] < a[i] && a[k] < b[j]){
                    if(ref[k][j] == 0)continue;
                    int get = dp[k][ref[k][j]]+1;
                    if(get > dp[i][j]){
                        dp[i][j] = get;
                        res[i] = k;
                    }
                }
            }
        }
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            if(dp[i][j] > mx){
                mx = dp[i][j];
                pos = i;
            }
        }
    }
    cout << mx << endl;
    vector<int>ans;
    while(pos!=0){
        ans.pb(a[pos]);
        pos = res[pos];
    }
    reverse(all(ans));
    for(auto x : ans)cout << x << ' ';
    cout << endl;
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