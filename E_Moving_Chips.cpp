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
    int n;
    cin >> n;
    vector<vector<char>>a(3, vector<char>(n+1));
    for(int i= 1;i<=2;++i){
        for(int j = 1;j<=n;++j)cin>> a[i][j];
    }
    int prefc = 0, suffc = 0;
    for(int i = 1;i<=n;++i){
        if(a[1][i] == '*' || a[2][i] == '*')break;
        prefc++;
    }
    for(int i = n;i>=1;--i){
        if(a[1][i]=='*' || a[2][i] == '*')break;
        suffc++;
    }
    int m = n-prefc-suffc;
    vector<vector<char>>b(3, vector<char>(m+1));
    for(int i = prefc+1;i<=n-suffc;++i){
        b[1][i-prefc] = a[1][i];
        b[2][i-prefc] = a[2][i];
    }
    vector<vector<int>>dpr(3, vector<int>(m+1)),dpl(3,vector<int>(m+1));
    if(b[2][m]=='*')dpr[1][m] = 1;
    if(b[1][m] == '*')dpr[2][m] = 1;
    for(int i = m-1;i>=1;--i){
        for(int j = 1;j<=2;++j){
            dpr[j][i] = min(dpr[j][i+1]+1+(b[3-j][i]=='*'),dpr[3-j][i+1]+2);
        }
    }
    if(b[1][1]=='*')dpl[2][1] = 1;
    if(b[2][1] == '*')dpl[1][1] = 1;
    for(int i = 2;i<=m;++i){
        for(int j = 1;j<=2;++j){
            dpl[j][i] = min(dpl[j][i-1]+1+(b[3-j][i]=='*'),dpl[3-j][i-1]+2);
        }
    }
    int res = 1e18;
    for(int i = 1;i<=m;++i){
        for(int j = 1;j<=2;++j){
            int c = 0;
            if(i > 1)c+=min(dpl[j][i-1]+1,dpl[3-j][i-1]+2);
            if(i < m)c+=min(dpr[j][i+1]+1,dpr[3-j][i+1]+2);

            if(i > 1 && i < m && (dpl[3-j][i-1]+dpr[3-j][i+1]+3) < c)c = dpl[3-j][i-1]+dpr[3-j][i+1]+3;
            c+=(b[3-j][i]=='*');
            res = min(res, c);
        }
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