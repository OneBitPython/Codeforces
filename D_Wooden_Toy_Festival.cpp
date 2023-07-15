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

vector<int>a;
int n;
bool pos(int x){
    vector<int>have = {0};
    for(int i = 1;i<=n;++i){
        have.pb(a[i]-x);
        have.pb(a[i]+x);
    }
    sort(all(have));
    have.erase(unique(all(have)),have.end());
    int m = have.size()-1;
    vector<int>dp(n+1,1e9); // dp[i] minimum numb3er of carvers required uptill i
    dp[0] = 0;
    for(int i = 1;i<=m;++i){
        int h = lower_bound(all(a),have[i]-x)-a.begin()-1;
        int w = upper_bound(all(a),have[i]+x)-a.begin()-1;
        dp[w] = min(dp[w],dp[h]+1);
    }
    return dp[n] <= 3;
}

void solve()
{
    cin >> n;
    a = vector<int>(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    
    sort(a.begin()+1, a.end());
    a[0] = -1e18;
    int l = 0, r = 1e10;
    int res= 0;
    while(l <= r){
        int m = (l+r)/2;
        if(pos(m))r = m-1, res = m;
        else l = m+1;
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