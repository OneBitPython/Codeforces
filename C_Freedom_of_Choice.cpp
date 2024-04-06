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
    map<int,vector<pair<int,int>>>mp;
    cin >> n;
    vector<vector<int>>a(1),c(1);
    vector<pair<int,int>>b(n+1);
    vector<int>big(n+1);
    int used = 0,mn = 0;
    set<int>x;
    for(int i = 1;i<=n;++i){
        int r;
        cin >> r;
        cin >> b[i].first >> b[i].second;
        used+=b[i].second;
        mn += b[i].first;
        vector<int>kk(r+1);
        for(int j  = 1;j<=r;++j)cin >> kk[j];
        a.pb(kk);
        for(int j = 1;j<=r;++j){
            cin >> kk[j];
            big[i] += kk[j];
            mp[a[i][j]].pb({i,kk[j]});
            x.insert(a[i][j]);
        }
        c.pb(kk);
    }
    int res = 1e18;
    if(used-mn > 1e5){
        cout << 0 << endl;
        return;
    }
    for(int val = mn;val<=used;++val){
        int ans = 0,tot = used;
        for(auto &[idx,c] : mp[val]){
            int get = big[idx] - c;
            if(get < b[idx].first){
                ans+=(b[idx].first-get);
                get = b[idx].first;
            }
            tot-=max(0ll,(b[idx].second-get));
        }
        if(tot < val)ans+=(val-tot);
        res = min(res, ans);
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