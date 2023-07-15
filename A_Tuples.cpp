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
    vector<pair<int,int>>b(n+1);
    int curr = 0, sum = 0, res = 0, tot = 0;
    for(int i = 1;i<=n;++i)cin >> b[i].first;
    for(int i = 1;i<=n;++i)cin >> b[i].second,curr+=b[i].second,tot+=b[i].first;
    vector<pair<int,int>>a;
    a.pb({0,0});
    for(int i = 1;i<=n;++i){
        if(b[i].second == 1)a.pb(b[i]);
    }
    vector<int>rest;
    for(int i = 1;i<=n;++i){
        if(b[i].second==-1)rest.pb(b[i].first);
    }
    sort(all(rest),greater<int>());
    for(auto x : rest)a.pb(make_pair(x,-1));

    for(int i = 1;i<=n;++i)res+=(a[i].first*curr);
    sum = res;

    if(curr==(-n))res = -a[n].first;
    for(int i = n;i>=1;--i){
        if(a[i].second==1)break;
        if(i==1)break;
        sum-=(a[i].first*curr);
        curr-=a[i].second;
        tot-=a[i].first;
        sum+=tot;
        res = max(res, sum);
    }
    cout << res << endl;
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