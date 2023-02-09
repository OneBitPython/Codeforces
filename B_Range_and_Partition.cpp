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
    int n,k;
    cin >> n >> k;
    vector<int>a(n), cnt(n+1);
    for(int &u : a)cin >>u , cnt[u]++;
    vector<int>pref(n+1);
    for(int i = 1;i<=n;++i)pref[i] = pref[i-1]+cnt[i];
    int l = 0, r = 0;
    int sz = 1e18;
    for(int i =1;i<=n;++i){
        // choose i as your x
        // now sum(cnt[x..y])-(n-sum[x..y]) >= k
        // sum(cnt[x..y])-n+sum[x..y] >= k
        // 2sum[x..y] >= k + n
        // 2 * pref[y] - 2*pref[x-1]>=k+n
        // pref[y] >= (k+n+2*pref[x-1])/2
        int val = (k+n+2*pref[i-1]+1)/2;
        int y = lower_bound(all(pref),val)-pref.begin();
        if(y>n)continue;
        if((y-i+1)<sz){
            sz = y-i+1;
            l = i;
            r = y;
        }
    }
    cout << l << ' ' << r << endl;
    int req = 1;
    int cur = 1;
    int sum = 0;
    for(int i = 0;i<n;++i){
        if(a[i] >= l && a[i] <= r)sum++;
        else sum--;
        if(sum==req && req < k){
            req++;
            cout << cur << ' ' << i+1 << endl;
            cur = i+2;

        }
    }
    cout << cur << ' ' << n << endl;
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