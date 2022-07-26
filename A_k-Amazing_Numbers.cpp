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
    int n;
    cin >> n;
    vector<vector<int>>a(n+1, vector<int>(1, -1));
    for(int i = 0;i<n;++i){
        int v;
        cin >> v;
        a[v].pb(i);
    }
    vector<pair<int,int>>c(n+1);
    vector<int>d(n+1);
    for(int i = 1;i<=n;++i){
        a[i].pb(n);
        int mx = 0;
        for(int j = 1;j<a[i].size();++j){
            mx = max(mx, a[i][j] - a[i][j-1]);
        }
        c[i] = {mx, i};
        d[i] = mx;
    }
    sort(all(c));
    sort(all(d));

    vector<int>pref(n+1);
    pref[1] = c[1].second;
    for(int i = 2;i<=n;++i)pref[i] = min(c[i].second, pref[i-1]);

    for(int k = 1;k<=n;++k){
        int l = upper_bound(all(d), k) - d.begin() - 1;
        if(l == 0){
            cout << -1 << ' ';
            continue;
        }
        cout << pref[l] << ' ';

    }
    cout << endl;
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