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
    int n,b,x;
    cin >> n >> b >> x;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    sort(a.begin()+1, a.end());
    int till = n+1;
    int res = 0;
    for(int i = 1;i<=n;++i)res+=((a[i]*(a[i]-1))/2 * b);
    res-=(a[n]-1)*x;
    int ans = res;
    for(int groups = a[n]-1;groups>=1;--groups){
        while(till > 1 && a[till-1] > groups)till--;
        res+=x;
        for(int j= till;j<=n;++j){
            int early = groups+1;
            int each = a[j]/early;
            int tot = (a[j]*(a[j]-1))/2 * b;
            int val = (each*(each-1))/2 * b * early + (a[j]%early)*each*b;
            res-=(tot-val);

            each = a[j]/groups;
            val = (each*(each-1))/2 * b * groups + (a[j]%groups)*each*b;
            res+=(tot-val);
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
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