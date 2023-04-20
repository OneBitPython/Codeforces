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

int n1, n2,n3,n4,m1,m2,m3;
vector<int>c;
int conv(int i, int j){
    int r = 0;
    for(int j = 1;j<i;++j)r+=c[j];
    return r+j;
}
int conv2(int i, int j){
    int r = j;
    for(int j = 1;j<i;++j)r-=c[j];
    return r;
}
void solve()
{

    cin >> n1 >> n2 >> n3 >> n4;
    c = {0, n1,n2,n3,n4};
    vector<vector<int>>a(5);
    for(int i = 1;i<=4;++i){
        a[i].resize(c[i]+1);
        for(int j = 1;j<=c[i];++j)cin >> a[i][j];
    }
    vector<vector<int>>adj(n1+n2+n3+n4+10);

    for(int i = 1;i<=3;++i){
        int k;
        cin >> k;
        for(int j = 1;j<=k;++j){
            int x,y;
            cin >> x >> y;
            adj[conv(i,x)].pb(conv(i+1,y));
        }
    }
    multiset<int>dp;
    vector<vector<int>>dpp(5);
    for(int i = 1;i<=4;++i)dpp[i].resize(c[i]+1,1e18);
    for(int i = 1;i<=n4;++i)dp.insert(a[4][i]),dpp[4][i] = a[4][i];

    for(int i = 3;i>=1;--i){
        multiset<int>ndp;
        for(int j = 1;j<=c[i];++j){
            for(int v: adj[conv(i,j)]){
                if(dpp[i+1][conv2(i+1,v)] != 1e18)dp.erase(dp.find(dpp[i+1][conv2(i+1,v)]));
            }
            if(!dp.empty()){
                dpp[i][j] = *dp.begin()+a[i][j];
                ndp.insert(dpp[i][j]);
            }
            for(int v: adj[conv(i,j)]){
                if(dpp[i+1][conv2(i+1,v)] != 1e18)dp.insert(dpp[i+1][conv2(i+1,v)]);
            }
        }
        dp = ndp;
    }
    int res = *min_element(dpp[1].begin()+1, dpp[1].end());
    if(res == 1e18)res = -1;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}