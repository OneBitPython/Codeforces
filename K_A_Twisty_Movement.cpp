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
    vector<int>a(n);
    for(int &u : a)cin >> u;
    vector<vector<int>>dp(n, vector<int>(n)); // dp[i][j] longest decreasing subsequence of [i,j]
    for(int i = 0;i<n;++i){
        vector<int>l;
        for(int j = i;j>=0;--j){
            auto pos = upper_bound(all(l),a[j]);
            if(pos == l.end())l.pb(a[j]);
            else *pos = a[j];
            dp[i][j] = (int)(l.size());
        }
    }
    vector<int>pref1(n),pref2(n);
    int c = 0;
    for(int i = 0;i<n;++i){
        if(a[i] == 1)c++;
        pref1[i] = c;
        pref2[i] = i-c+1;
    }
    /*
    you make 3 partitions, one for the suffix, one for the prefix and one for the subarray that you will be inverting
    prefix - only 1s, sub - only 1s, suf- 1s and 2s
    prefix - only 1s, sub - 1s and 2s, suff - only 2s
    prefix - 1s and 2s sub - 2s suff - 2s
    */
    int res = max(pref1[n-1], pref2[n-1]);
    for(int i = 0;i<n;++i){
        for(int j = i;j<n;++j){
            // j->i (backwards) denotes the subarray
            // [0,i-1] prefix
            // [i,j] sub
            // [j+1,n-1] suffix
            int c1 = 0, c2 = 0, c3 = 0;
            if(i > 0){
                c1 = pref1[i-1];
                c2 = pref1[i-1];
                c3 = dp[i-1][0];
            }
            c1+=pref1[j]-(i > 0?pref1[i-1]:0);
            c2 += dp[j][i];
            c3 += pref2[j]-(i>0?pref2[i-1]:0);
            if(j < n-1){
                c1 += dp[n-1][j+1];
                c2 += pref2[n-1] - pref2[j];
                c3 += pref2[n-1] - pref2[j];
            }
            res = max({res, c1, c2, c3});
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