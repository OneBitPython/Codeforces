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
    int m,n;
    cin >> m >> n;
    vector<vector<int>>a(m+1, vector<int>(n+1));
    for(int i =1 ;i<=m;++i){
        for(int j = 1;j<=n;++j)cin >> a[i][j];
    }
    vector<int>c = {0};
    for(int i = 1;i<=n;++i){
        int mx = 0; 
        for(int j = 1;j<=m;++j){
            mx = max(mx, a[j][i]);
        }
        c.pb(mx);
    }
    if(m < n){
        cout << *min_element(c.begin()+1, c.end()) << endl;
        return;
    }
    vector<vector<int>>cost(n+1, vector<int>(n+1));
    for(int i = 1;i<=n;++i){
        for(int j = i+1;j<=n;++j){
            int mn = 1e18;
            for(int k = 1;k<=n;++k){
                if(k==i || k == j)continue;
                mn = min(mn, c[k]);
            }
            cost[i][j] = mn;
        }
    }
    int res = 0;
    for(int i = 1;i<=m;++i){
        for(int j = 1;j<=n;++j){
            for(int k =j+1;k<=n;++k){
                int mn = min({cost[j][k],a[i][j],a[i][k]});
                res = max(res, mn);
            }
        }
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