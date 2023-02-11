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
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<vector<int>>open(n+1, vector<int>(n+1)), close(n+1, vector<int>(n+1)), diff(n+1, vector<int>(n+1));
    for(int i = 2;i<=n;i+=2){
        int c = 0, o = 0, d = 0;
        for(int j = i;j<=n;++j){
            if((j%2) == 0)c+=a[j];
            else o+=a[j];
            d = max(d, c-o);
            close[i][j] = c;
            open[i][j] = o;
            diff[i][j] = d;
        }
    }
    int res = 0;
    for(int i = 1;i<n;i+=2){
        res+=min(a[i],a[i+1]);
    }
    for(int i = 1;i<=n;i+=2){
        for(int j = i+3;j<=n;j+=2){
            // i opens and j closes
            int req = diff[i+1][j-1];
            if(req > a[i])continue;
            int curr_op = open[i+1][j-1]+req;
            int need = curr_op - close[i+1][j-1];
            if(need < 0 || a[j] < need)continue;
            res+=min(a[i]-req+1,a[j]-need+1);
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}