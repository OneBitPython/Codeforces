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
    cin >>n;
    vector<pair<int,int>>a(n);
    int mx = 0;
    for(int i= 0;i<n;++i){
        cin >> a[i].first >> a[i].second;
        mx = max(mx, a[i].first);
        mx = max(mx, a[i].second);
    }
    if(n==1){
        cout << 2*(a[0].first+a[0].second) << endl;
        return;
    }
    vector<int>pref(n);
    pref[0] = min(a[0].first,a[0].second);
    for(int i =1;i<n;++i)pref[i] = pref[i-1]+min(a[i].first,a[i].second);
    vector<int>suff(n);
    suff.back() = min(a.back().first,a.back().second);
    for(int i = n-2;i>=0;--i)suff[i] = suff[i+1]+min(a[i].first,a[i].second);

    int res = 1e18;
    for(int i = 0;i<n;++i){
        int cost_back = 0, cost_front = 0;
        if(i > 0)cost_back = 2*pref[i-1];
        if(i < n-1)cost_front = 2*suff[i+1];
        if(a[i].first == mx || a[i].second == mx){
            int cost = 2*(a[i].first+a[i].second)+cost_back+cost_front;
            res = min(res, cost);
        }
    }
    cout << res << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}