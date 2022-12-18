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
    int n,m;
    cin >> n >> m;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    int sz = sqrt(n);
    vector<vector<int>>queries;
    for(int i = 0;i<m;++i){
        int l,r;
        cin >> l >> r;
        queries.pb({l-1, r-1, i});
    }
    map<int,int>coord;
    set<int>b(all(a));
    int g = 1;
    vector<int>mp(2e5);
    for(auto x : b){
        coord[x] =g;
        mp[g] = x;
        g++;
    }
    vector<int>ar;
    for(auto x : a)ar.pb(coord[x]);
    vector<int>res(m);
    vector<int>cnt(g+1);
    int l = 0, r = -1;
    sort(all(queries), [&](auto one, auto two){
        int o = one[0]/sz, t = two[0]/sz;
        if(o != t)return o < t;
        return one[1] < two[1];
    });
    int ans = 0;
    for(int i = 0;i<m;++i){
        while(l > queries[i][0]){
            l--;
            if(cnt[ar[l]]==mp[ar[l]])ans--;
            cnt[ar[l]]++;
            if(cnt[ar[l]]==mp[ar[l]])ans++;
        }
        while(r < queries[i][1]){
            r++;
            if(cnt[ar[r]]==mp[ar[r]])ans--;
            cnt[ar[r]]++;
            if(cnt[ar[r]]==mp[ar[r]])ans++;

        }
        while(l < queries[i][0]){
            if(cnt[ar[l]]==mp[ar[l]])ans--;
            cnt[ar[l]]--;
            if(cnt[ar[l]]==mp[ar[l]])ans++;
            l++;
        }
        while(r > queries[i][1]){
            if(cnt[ar[r]]==mp[ar[r]])ans--;
            cnt[ar[r]]--;
            if(cnt[ar[r]]==mp[ar[r]])ans++;
            r--;
        }
        res[queries[i][2]] = ans;
    }
    for(auto x : res)cout << x << endl;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}