#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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
    int n,x;
    cin >> n >> x;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    int taken_l = *min_element(all(a)), taken_r = *max_element(all(a));
    pair<int,int>up, down;
    up.first = up.second = down.first = down.second = -1;
    if(taken_r + 1 <= x){
        up.first = taken_r+1;
        up.second = x;

    }
    if(taken_l - 1 >= 1){
        down.first = 1;
        down.second = taken_l-1;
    }
    
    vector<int>upc(n+1), downc(n+1);
    if(up.first != -1)upc[0] = up.second-up.first + (min(abs(a[0] - up.second), abs(a[0] - up.first)));
    for(int i = 0;i<n-1;++i){
        if(up.first == -1)continue;
        int l = min(a[i], a[i+1]), r = max(a[i], a[i+1]);
        upc[i+1] = up.second - up.first + (up.first - l)+(up.second - r) - (r-l);
    }
    if(up.first != -1)upc[n] = up.second - up.first + (min(abs(a.back() - up.second), abs(a.back() - up.first)));

    if(down.first != -1)downc[0] = down.second-down.first + (min(abs(a[0] - down.second), abs(a[0] - down.first)));
    for(int i = 0;i<n-1;++i){
        if(down.first == -1)continue;
        int l = min(a[i], a[i+1]), r = max(a[i], a[i+1]);
        downc[i+1] = down.second - down.first + (l-down.first) + (r-down.second) - (r-l);
    }
    if(down.first != -1)downc[n] = down.second - down.first + (min(abs(a.back() - down.second), abs(a.back() - down.first)));
    int res = 1e18;
    int tot = 0;
    for(int i = 0;i<n-1;++i)tot+=(abs(a[i]-a[i+1]));


    vector<int>pre2(n+1), suff2(n+1);
    pre2[0] = downc[0];
    suff2.back() = downc.back();

    for(int i = 1;i<=n;++i)pre2[i] = min(pre2[i-1], downc[i]);
    for(int i = n-1;i>=0;--i)suff2[i] = min(suff2[i+1], downc[i]);
    for(int i = 0;i<=n;++i){
        int val1 = 1e18, val2 = 1e18;
        if(i > 0)val1 = pre2[i-1];
        if(i < n)val2 = suff2[i+1];
        int cost = upc[i]+min(val1, val2);
        res = min(res, tot+cost);
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