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

vector<int>cnt(1e6+5);

void solve()
{
    int n,m,k;
    cin >>n >> m >> k;
    vector<int>a(n);
    for(int &u :a)cin >> u;
    vector<int>pref(n);
    pref[0] = a[0];
    for(int i = 1;i<n;++i)pref[i] = pref[i-1]^a[i];
    int sz = sqrt(n);
    int mx = *max_element(all(pref));
    cnt.resize(mx+1);
    vector<vector<int>>queries;
    for(int i = 0;i<m;++i){
        int l,r;
        cin >> l >> r;
        queries.pb({l-1,r-1,i});
    }
    sort(all(queries), [&](auto one, auto two){
        int o = one[0]/sz, t = two[0]/sz;
        if(o==t)return one[1] < two[1];
        return o < t;
    });
    int l = 0, r = -1;
    int res = 0;
    vector<int>ans(m);
    for(int i = 0;i<m;++i){
        while(l > queries[i][0]){
            l--;
            cnt[pref[l]]++;
            int val = 0;
            if(l > 0)val = pref[l-1];
            int req = val^k;
            res+=cnt[req];
        }
        while(r < queries[i][1]){
            r++;
            int req = pref[r]^k;
            res+=cnt[req];
            int val = 0;
            if(l > 0) val = pref[l-1];
            if(req==val)res++;
            cnt[pref[r]]++;
        }
        while(l < queries[i][0]){
            int val = 0;
            if(l > 0)val = pref[l-1];
            int req = val^k;
            res-=cnt[req];
            cnt[pref[l]]--;
            l++;
        }
        while(r > queries[i][1]){
            int req = pref[r]^k;
            cnt[pref[r]]--;
            res-=cnt[req];
            int val = 0;
            if(l > 0 )val = pref[l-1];
            if(req == val)res--;
            r--;
        }
        ans[queries[i][2]]= res;
    }
    for(auto x : ans)cout << x << endl;
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