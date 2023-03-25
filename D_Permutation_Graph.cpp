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
    vector<int>ng(n+1), nl(n+1);
    stack<int>st;
    for(int i = 1;i<=n;++i){
        while(!st.empty() && a[st.top()] > a[i])st.pop();
        if(st.empty())nl[i] = -1;
        else nl[i] = st.top();
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i = 1;i<=n;++i){
        while(!st.empty() && a[st.top()] < a[i])st.pop();
        if(st.empty())ng[i] = -1;
        else ng[i] = st.top();
        st.push(i);
    }
    vector<vector<int>>up1(n+1, vector<int>(21)), dp1(n+1, vector<int>(21,1e18));
    vector<vector<int>>up2(n+1, vector<int>(21)), dp2(n+1, vector<int>(21,1e18));

    /*
    up1[i][j] stores the 2^jth ancestor of the ith node when edges ar made from i->nl[i]
    dp1[i][j] stores the minimum from [2^jth ancestor, i] when edges are made from i-> nl[i]

    up2[i][j] stores the 2^jth ancestor of the ith node when edges ar made from i->ng[i]
    dp2[i][j] stores the minimum from [2^jth ancestor, i] when edges are made from i-> ng[i]

    */
    vector<int>dp(n+1); // dp[i] stores the min cost to raech position i
    dp1[1][0] = dp2[1][0] = 0;
    for(int i = 2;i<=n;++i){
        if(nl[i]!=-1){
            up1[i][0] = nl[i];
            for(int j = 1;j<=20;++j)up1[i][j] = up1[up1[i][j-1]][j-1];
            dp1[i][0] = dp[nl[i]];
            for(int j = 1;j<=20;++j)dp1[i][j] = min(dp1[i][j-1],dp1[up1[i][j-1]][j-1]);
        }
        if(ng[i]!=-1){
            up2[i][0] = ng[i];
            for(int j = 1;j<=20;++j)up2[i][j] = up2[up2[i][j-1]][j-1];
            dp2[i][0] = dp[ng[i]];
            for(int j = 1;j<=20;++j)dp2[i][j] = min(dp2[i][j-1],dp2[up2[i][j-1]][j-1]);
        }
        if(a[i] > a[i-1]){
            // use edges from nl
            int till = max(0ll,ng[i]);
            int p = i;
            int res = dp[i-1];
            for(int j = 20;j>=0;--j){
                if(up1[p][j]<=till)continue;
                res = min(res, dp1[p][j]);
                p = up1[p][j];
            }
            dp[i] = res+1;
        }else{
            // use edges from ng
            int till = max(0ll,nl[i]);
            int p =i;
            int res = dp[i-1];
            for(int j = 20;j>=0;--j){
                if(up2[p][j]<=till)continue;
                res = min(res, dp2[p][j]);
                p = up2[p][j];
            }
            dp[i] = res+1;
        }
    }
    cout << dp[n] << endl;
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