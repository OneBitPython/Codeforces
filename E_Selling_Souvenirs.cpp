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

int give_ones(int twos, int i){
    int ones = i-(2*twos);
    return ones;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>a(4), pref(4);
    for(int i = 0;i<n;++i){
        int w,c;
        cin >> w >> c;
        a[w].pb(c);
    }
    for(int i = 1;i<=3;++i){
        sort(all(a[i]),greater<int>());
    }
    for(int i = 1;i<=3;++i){
        vector<int>p;
        int c = 0;
        for(auto x : a[i]){
            c+=x;
            p.pb(c);
        }
        pref[i] = p;
    }
    vector<pair<int,int>>dp(m+1);
    // dp[i].second number of twos present in the best possible sum of weight i, including only items of weight 1 and 2
    // dp[i].first is the max possible cost if you take values of weight only 1 and 2
    if(!a[1].empty())dp[1].first = a[1][0];
    int res = dp[1].first;
    for(int i = 2;i<=m;++i){
        // you can add a new 1 to i-1
        int take = give_ones(dp[i-1].second, i-1);
        dp[i].second = dp[i-1].second;
        dp[i].first = dp[i-1].first;
        if(take < (int)(a[1].size()))dp[i].first+=a[1][take];

        // you can add a new 2 to i-2
        take = dp[i-2].second;
        if(take < (int)(a[2].size())){
            int get = dp[i-2].first + a[2][take];
            if(get > dp[i].first){
                dp[i].second = dp[i-2].second+1;
                dp[i].first = get;
            }
        }
        res = max(res, dp[i].first);
    }
    for(int i = 0;i<=m;++i){
        if((i+1)*3 > m)break;
        if(i >= (int)(pref[3].size()))break;
        int cost = (pref[3][i])+dp[m-(3*(i+1))].first;
        res = max(res, cost);
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