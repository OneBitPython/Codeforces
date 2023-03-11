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
int cnt[200001];

int give(int n){
    // nc3
    int res = (n-2)*(n-1)*n;
    return res/6;
}
int ans = 0;
vector<int>a;
void remove(int x){
    ans-=give(cnt[a[x]]);
    cnt[a[x]]--;
    ans+=give(cnt[a[x]]);
}
void add(int x){
    ans-=give(cnt[a[x]]);
    cnt[a[x]]++;
    ans+=give(cnt[a[x]]);
}
void solve()
{
    int n,q;
    cin >> n >> q;
    a.resize(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    int sz = sqrtl(n);
    vector<vector<int>>queries;
    for(int i = 0;i<q;++i){
        int l,r;
        cin >> l>> r;
        queries.pb({i, l, r});
    }
    sort(all(queries), [&](auto one, auto two){
        int g1 = one[1]/sz, g2 = two[1]/sz;
        if(g1 == g2)return one[2] < two[2];
        return g1 < g2;
    });
    vector<int>res(q);
    int l = 1, r = 0;
    for(auto x : queries){
        while(l < x[1]){
            remove(l);
            l++;
        }
        while(l > x[1]){
            l--;
            add(l);
        }

        while(r < x[2]){
            r++;
            add(r);
        }
        while(r > x[2]){
            remove(r);
            r--;
        }
        res[x[0]] = ans;
    }   
    for(int i = 0;i<q;++i)cout << res[i] << endl;
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