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
    vector<int>suff1(n+2), suff0(n+2), pref1(n+1), pref0(n+1);
    for(int i = 1;i<=n;++i){
        pref0[i] = pref0[i-1] + (a[i]==0);
        pref1[i] = pref1[i-1] + (a[i]==1);
    }
    for(int i = n;i>=0;--i){
        suff0[i] = suff0[i+1] + (a[i]==0);
        suff1[i] = suff1[i+1] + (a[i]==1);
    }
    int res = 0;
    for(int i = 1;i<=n;++i){
        if(a[i] == 1)res+=(suff0[i+1]);
    }
    int ans = res;
    for(int i = 1;i<=n;++i){
        int tmp = res;
        if(a[i] == 1){
            tmp+=pref1[i-1];
            tmp-=suff0[i+1];
        }else{
            // 0 to 1
            tmp-=pref1[i-1];
            tmp+=suff0[i+1];
        }
        ans = max(ans, tmp);
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
    // #endif

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}