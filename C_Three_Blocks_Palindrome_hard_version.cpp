#include <bits/stdc++.h>
using namespace std;

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

const int mxn = 2e5+5;
int pref[201][mxn];
vector<int>pos[201];
void solve()
{
    int n;
    cin >> n;
    vector<int>a;
    for(int i = 0;i<=200;++i)pos[i].clear();
    for(int i = 0;i<n;++i){
        int c;
        cin >> c;
        a.pb(c);
        pos[c].pb(i);
    }
    int res = 0;
    for(int i = 1;i<=200;++i){
        int c = 0;
        for(int j = 0;j<n;++j){
            if(a[j] == i)c++;
            pref[i][j] = c;
        }
        res = max(res, c);
    }
    for(int i = 1;i<=200;++i){
        for(int j = 1;j<=200;++j){
            if(i==j)continue;
            int m = pos[i].size();
            for(int x = 1;x<m;++x){
                int st = pos[i][x-1],ba = pos[i][m-x];
                if(st+1 >= ba)break;
                res = max(res, x * 2 + pref[j][ba-1]-pref[j][st]);
            }   
        }
    }
    cout << res << endl;
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