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
    int l = log2(n);
    int val = (1ll<<l)-1;
    vector<int>res;
    for(int i = 0;i<=30;++i){
        if(val&(1ll<<i))res.pb((1ll<<i));
    }
    int rem = n-val;
    res.pb(rem);
    sort(all(res));
    cout << (int)(res.size())-1 << endl;
    for(int i = 1;i<(int)(res.size());++i){
        cout << res[i]-res[i-1] << ' ';
    }
    cout << endl;
    // vector<vector<int>>dp(n+1);
    // dp[1] = {1};
    // for(int i = 2;i<=n;++i){
    //     int x = (i+1)/2;
    //     vector<int>best;
    //     int sz = 1e18;
    //     for(int j = 1;j<i;++j){
    //         int val = dp[j].back();
    //         if(j+val*2<i)continue;
    //         int req = i-j;
    //         if((val)>req)continue;

    //         if(req >= dp[j].back() && dp[j].size()+1 < sz){
    //             best = dp[j];
    //             best.pb(req);
    //             sz = best.size();
    //         }
    //     }
    //     dp[i] = best;
    // }
    // for(int i =1;i<=n;++i){
    //     dbg(i,dp[i]);
    // }
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