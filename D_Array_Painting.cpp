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
    vector<int>a(n+2);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<int>taken(n+2);
    taken[0] = taken[n+1] = 1;
    int sz = 0, lst = 1;
    vector<pair<int,int>>ranges;
    int res = 0;
    for(int i = 1;i<=n;++i){
        if(a[i])taken[i] = 1;
        if(a[i]>0)sz++;
        else{
            if(sz){
                res++;
                ranges.pb({lst,i-1});
            }
            sz = 0;
            lst = i+1;
        }
    }
    if(sz){
        res++;
        ranges.pb({lst,n});
    }
    vector<pair<int,int>>ones;
    for(int i = 0;i<ranges.size();++i){
        bool has = 0;
        for(int j = ranges[i].first;j<=ranges[i].second;++j)has|=(a[j]==2);
        if(has){
            taken[ranges[i].first-1] = 1;
            taken[ranges[i].second+1] = 1;
        }else{
            ones.pb(ranges[i]);
        }
    }
    vector<pair<int,int>>imp;
    for(int i = 0;i<ones.size();++i){
        int u = ones[i].first, v = ones[i].second;
        if(taken[u-1] && taken[v+1])continue;
        if(taken[u-1] && !taken[v+1])taken[v+1] = 1;
        else if(taken[v+1] && !taken[u-1])taken[u-1] = 1;
    }
    for(int i = (int)(ones.size())-1;i>=0;--i){
        int u = ones[i].first, v = ones[i].second;
        if(taken[u-1] && taken[v+1])continue;
        if(taken[u-1] && !taken[v+1])taken[v+1] = 1;
        else if(taken[v+1] && !taken[u-1])taken[u-1] = 1;
        else imp.pb(ones[i]);
    }

    for(auto x : imp)taken[x.first-1] = 1;
    for(int i = 1;i<=n;++i){
        if(!taken[i])res++;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}