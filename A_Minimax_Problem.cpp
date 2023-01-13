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


vector<vector<int>>a;
int n,m;
int first = 0, second = 0;
bool pos(int x){
    // if a[i][j] >= x then the jth bit of ith value is set otherwise it's not set
    // find two values with or = 2^m-1
    int u = (1ll<<m);
    map<int,vector<int>>cnt;
    for(int i = 0;i<n;++i){
        int val = 0;
        for(int j = 0;j<m;++j){
            if(a[i][j]>=x)val+=(1ll<<j);
        }
        if(cnt[val].size()>=2)continue;
        cnt[val].pb(i);
    }
    for(int i = 0;i<u;++i){
        for(int j = 0;j<u;++j){
            if((i|j)!=(u-1))continue;
            if(i==j){
                if(cnt[i].size()==2){
                    first = cnt[i][0];
                    second = cnt[i][1];
                    return 1;
                }
            }else{
                if(cnt[i].empty()||cnt[j].empty())continue;
                first = cnt[i][0];
                second = cnt[j][0];
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    int l = -1, r = 1e9+5;
    cin >> n >> m;
    a = vector<vector<int>>(n, vector<int>(m));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j)cin >> a[i][j];
    }
    while(l + 1 < r){
        int m = (l+r)/2;
        if(pos(m))l = m;
        else r = m;
    }
    cout << first+1 << ' ' << second+1 << endl;
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