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
    int n,m,k;
    cin >> n >> m >> k;
    set<int>xx,yy;
    vector<int>xs,ys;
    for(int i = 1;i<=n;++i){
        int v;
        cin >> v;
        xs.pb(v);
        xx.insert(v);
    }
    for(int i = 1;i<=m;++i){
        int v;
        cin >> v;
        ys.pb(v);
        yy.insert(v);
    }
    vector<pair<int,int>>xstreet,ystreet;
    for(int i = 1;i<=k;++i){
        int x,y;
        cin >> x >> y;
        if(xx.count(x)&&yy.count(y))continue;
        if(xx.count(x))xstreet.pb({x,y});
        else ystreet.pb({x,y});
    }
    sort(all(xstreet), [&](auto one, auto two){
        return one.second < two.second;
    });
    sort(all(ystreet), [&](auto one, auto two){
        return one.first < two.first;
    });
    int p = 0;
    int res = 0;
    for(int i = 0;i<m-1;++i){
        // fidn number of xstreetcoordsd between ys[i] and ys[i+1]
        map<int,int>cnt;
        int tot = 0;
        while(p < (int)(xstreet.size()) && xstreet[p].second >= ys[i] && xstreet[p].second <= ys[i+1]){
            res-=cnt[xstreet[p].first];
            cnt[xstreet[p].first]++;
            p++;
            tot++;
        }
        res+=(tot*(tot-1))/2;
    }
    p = 0;
    for(int i = 0;i<n-1;++i){
        map<int,int>cnt;
        int tot = 0;
        while(p < (int)(ystreet.size()) && ystreet[p].first >= xs[i] && ystreet[p].first <= xs[i+1]){
            res-=cnt[ystreet[p].second];
            cnt[ystreet[p].second]++;
            p++;
            tot++;
        }
        res+=(tot*(tot-1))/2;
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