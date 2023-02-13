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

bool square(int x){
    int y = sqrtl(x);
    if((y*y)==x)return 1;
    return 0;
}
int give(vector<int>a, int x){
    int res = 0;
    int n = a.size();
    for(int i = 1;i<n;++i)if(square(a[i]+x))res++;
    return res;
}
int fact(int k, int i, int j, vector<int>a){
    int t = (k+((a[j]-a[i])/k))/2;
    if((t*t)-a[j] < 0)return 1ll;
    int ret = give(a,(t*t)-a[j]);
    return ret;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    /*
    a[i]+x = s^2
    a[j]+x = t^2
    a[j]-a[i] = t^2-s^2
    a[j]-a[i] = (t+s)(t-s)
    let d be a factor of a[j]-a[i]
    t+s = d
    t-s = (a[j]-a[i])/d

    t = (d+((a[j]-a[i])/d))/2
    s = d-t

    x = t^2 - a[j]
    try this x and find max squareness
    */
    int res = max(1ll,give(a,0));
    for(int i = 1;i<=n;++i){
        for(int j = i+1;j<=n;++j){
            int val = a[j]-a[i];
            for(int k = 1;k*k<=val;++k){
                if(val%k == 0){
                    res = max(res, fact(k,i,j,a));
                    res = max(res, fact(val/k,i,j,a));
                }
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