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
    /*
    the ending position of each song remains the same and it will be the last position such that it isthe max in the prefix
    now sort the values by their ending position in non decreasing order

    let the max of each song be xi, placing a song with greater xi before xj leaves all values in xj redundant

    once sorted by xi do dp where dp[i] stores the max coolness applicable, you can go through all tracks of the current song and binary search on first position that is <xi then add val[i][j] which denotes the max length sequence of the ith song starting at the jth track
    the valus of dp[i] will be non decreasing because since you can just continue of dp[i-1] in the worst case
    */
    int n;
    cin >> n;
    vector<vector<int>>a(n+1);
    vector<int>pos(n+1,1); // pos of the last value in each song
    vector<vector<int>>val(n+1); // val[i][j] stores the max length path starting from the jth track in i
    vector<pair<int,int>>b;
    for(int i =1;i<=n;++i){
        int k;
        cin >> k;
        a[i].resize(k+1);
        vector<int>pref(k+1);
        for(int j = 1;j<=k;++j)cin >> a[i][j],pref[j] = max(pref[j-1],a[i][j]);
        // compute pos[i];
        for(int j = k;j>=2;--j){
            if(a[i][j]>pref[j-1]){
                pos[i] = j;
                break;
            }
        }
        val[i].resize(k+1);
        stack<int>st;
        for(int j = pos[i];j>=1;--j){
            while(!st.empty() && a[i][j]>=a[i][st.top()])st.pop();
            if(st.empty())val[i][j] = 1;
            else val[i][j] = val[i][st.top()]+1;
            st.push(j);
        }
        b.pb({a[i][pos[i]],i});
    }
    sort(all(b));
    vector<vector<int>>c(n+1);
    vector<int>d(n+1);
    for(int i= 1;i<=n;++i)c[i] = a[b[i-1].second],d[i] = b[i-1].first;
    vector<int>dp(n+1);
    for(int i= 1;i<=n;++i){
        int k = c[i].size();
        dp[i] = dp[i-1];
        vector<int>pref(k);
        for(int j = 1;j<k;++j)pref[j] = max(pref[j-1],c[i][j]);
        for(int j = 1;j<k;++j){
            // find first position in d that is <a[i][j]
            if(c[i][j]>pref[j-1]){
                int p = lower_bound(all(d),c[i][j])-d.begin()-1;
                dp[i] = max(dp[i],dp[p]+val[b[i-1].second][j]);
            }
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