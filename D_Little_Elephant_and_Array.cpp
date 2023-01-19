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

void erase(int x, vector<int>&cnt, int &ans){
    if(cnt[x]==x)ans--;
    cnt[x]--;
    if(cnt[x]==x)ans++;
}
void add(int x, vector<int>&cnt, int &ans){
    if(cnt[x]==x)ans--;
    cnt[x]++;
    if(cnt[x]==x)ans++;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    for(int i = 0;i<n;++i){
        if(a[i]>n)a[i] = n+1;
    }
    int sz = sqrtl(n);
    vector<vector<int>>queries;
    for(int i = 0;i<m;++i){
        int l,r;
        cin >> l >> r;
        queries.pb({l-1, r-1, i});
    }
    sort(all(queries), [&](auto one, auto two){
        int g1 = one[0]/sz, g2 = two[0]/sz;
        if(g1==g2)return one[1] < two[1]; 
        return g1 < g2;
    });
    int r=-1, l = 0;
    vector<int>res(m),cnt(n+5);
    int ans = 0;
    for(auto x : queries){
        while(l > x[0]){
            l--;
            add(a[l], cnt, ans);
        }
        while(l < x[0]){
            erase(a[l], cnt, ans);
            l++;
        }
        while(r < x[1]){
            r++;
            add(a[r], cnt,ans);
        }
        while(r > x[1]){
            erase(a[r], cnt, ans);
            r--;
        }
        res[x[2]] = ans;
    }
    for(auto x  : res)cout << x << endl;
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