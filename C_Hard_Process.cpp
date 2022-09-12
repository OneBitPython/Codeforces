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
    int k;
    cin>> n >> k;
    vector<int>a(n);
    for(int i = 0;i<n;++i)cin >> a[i];
    vector<int>dp(n);
    vector<int>pref(n);
    pref[0] = !a[0];
    for(int i = 1;i<n;++i)pref[i] = pref[i-1]+!a[i];
    for(int i = 0;i<n;++i){
        int sz = 0;
        if(a[i] == 0){
            dp[i] = i;
            continue;
        }
        int j = i;
        for(;j<n;++j){
            if(a[j] == 0){
                break;
            }
        }
        for(int k = i;k<j;++k)dp[i] = j-1;
        i = j-1;
    }
    vector<pair<int,int>>ranges;
    for(int i = 0;i<n;++i){
        int val = dp[i];
        if(val>=n)continue;
        int req = pref[val]+k-!a[i];
        int idx = upper_bound(all(pref), req) - pref.begin() - 1;
        if(idx<n-1){
            if(a[idx+1]==1)idx = dp[idx+1];
        }
        int l = idx-i+1;
        ranges.pb({l,i});
    }
    sort(all(ranges));
    reverse(all(ranges));
    int mx = 0;
    int sz = 0;
    for(int i = 0;i<n;++i){
        if(a[i] == 1)sz++;
        else{
            mx = max(mx, sz);
            sz = 0;
        }
    }
    mx =max(mx, sz);
    if(ranges.empty()){
        cout << mx << endl;
        for(auto x : a)cout << x << ' ';
        cout <<endl;
    }else{
        cout << ranges[0].first << endl;
        vector<int>res = a;
        for(int i = ranges[0].second;i<ranges[0].second+ranges[0].first;++i){
            res[i] = 1; 
        }
        for(auto x : res)cout << x << ' ';
        cout << endl;
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