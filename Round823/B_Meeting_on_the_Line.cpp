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

bool pos(double m, vector<double>&x, vector<double>&t, double &ans){
    vector<pair<double,double>>ranges;
    for(int i = 0;i<x.size();++i){
        double rem = m-t[i];
        if(rem < 0)return 0;
        ranges.pb({x[i]-rem, x[i]+rem});
    }
    double l = ranges[0].first, r = ranges[0].second;
    for(int i = 1;i<ranges.size();++i){
        l = max(l, ranges[i].first);
        r = min(r, ranges[i].second);
        if(l > r)return 0;
    }
    ans = (l+r)/2;
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<double>x(n), t(n);
    for(double &u : x)cin >>u;
    for(double & u : t)cin >> u;


    double l = -1, r = 1e9;
    double ans = x[0];
    for(int i = 0;i<=60;++i){
        double m = (l+r)/2;
        if(pos(m,x,t,ans))r = m;
        else l = m;
    }
    cout << fixed << setprecision(15) <<  ans << endl;
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