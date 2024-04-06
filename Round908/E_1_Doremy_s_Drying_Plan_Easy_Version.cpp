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
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,int>>ranges = {{0,0}};
    vector<int>diff(n+2);
    for(int i = 1;i<=m;++i){
        int l,r;cin >> l >> r;
        ranges.pb({l,r});
        diff[l]++;
        diff[r+1]--;
    }
    sort(all(ranges), [&](auto one, auto two){
        if(one==two)return false;
        return one.second < two.second;
    });
    vector<int>rain(n+1);
    for(int i = 1;i<=n;++i)rain[i] = rain[i-1] + diff[i];
    vector<int>pref2(n+1),pref1(n+1);
    for(int i = 1;i<=n;++i)pref2[i] =pref2[i-1] + (rain[i]==2),pref1[i] = pref1[i-1] + (rain[i]==1);
    vector<int>get(m+1);// get[i] denotes the number of '1' rainy days covered by range i
    for(int i = 1;i<=m;++i)get[i] = pref1[ranges[i].second] - pref1[ranges[i].first-1];
    // for each '2' rainy day find the day that contains it
    vector<pair<int,int>>contains(n+1); // contains[i] stores the two ranges that contain a '2' rainy day

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