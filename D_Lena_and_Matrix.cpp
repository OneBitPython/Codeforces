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
    vector<vector<int>>a(n+1, vector<int>(m+1));
    vector<pair<int,int>>imp;
    vector<vector<int>>pos(m+1);
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            char x;
            cin >> x;
            if(x=='B')a[i][j] = 1;
        }
        for(int j =1;j<=m;++j){
            if(a[i][j]){
                imp.pb({i,j});
                pos[j].pb(i);
                break;
            }
        }
        for(int j = m;j>=1;--j){
            if(a[i][j]){
                imp.pb({i,j});
                pos[j].pb(i);
                break;
            }
        }
    }
    int x = 1, y = 1, mn = 1e18;
    for(int i = 1;i<=n;++i){
        vector<int>di(m+1);
        int distleft = -1; // max distance to a node to the left of current node
        bool got = 0;
        for(int j = 1;j<=m;++j){
            if(got)distleft++;
            for(auto p : pos[j]){
                int d = abs(i-p);
                if(d > distleft){
                    distleft = d;
                    got = 1;
                }
            }
            di[j] = distleft;
        }
        int distright = -1;
        got = 0;
        for(int j = m;j>=0;--j){
            if(got)distright++;
            for(auto p : pos[j]){
                int d = abs(i-p);
                if(d > distright){
                    distright = d;
                    got = 1;
                }
            }
            di[j] = max(di[j],distright);
            if(di[j] < mn){
                mn = di[j];
                x = i;
                y = j;
            }
        }
    }
    cout << x << ' ' << y << endl;
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