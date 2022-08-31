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


int cost(int a, int b, int A, int B, vector<vector<int>>&p){
    return p[A][B] - p[a-1][B] - p[A][b-1] + p[a-1][b-1];
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>>a(n+2,vector<char>(m+2));
    vector<vector<int>>c(n+2,vector<int>(m+2)),d(n+2,vector<int>(m+2)), e(n+2,vector<int>(m+2));
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            cin >> a[i][j];
            if(a[i][j] == '#')c[i][j] = 4;
        }
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            if(j < m){
                if(a[i][j] == a[i][j+1] && a[i][j] == '#')d[i][j] = 2;
            }
        }
    }
    for(int i = 1;i<n;++i){
        for(int j = 1;j<=m;++j){
            if(a[i][j] == a[i+1][j] && a[i][j] == '#')e[i][j] = 2;
        }
    }
    vector<vector<int>>p1(n+2, vector<int>(m+2)), p2(n+2, vector<int>(m+2)),p3(n+2, vector<int>(m+2));
    for(int i =1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            p1[i][j] = p1[i-1][j] + p1[i][j-1] - p1[i-1][j-1] + c[i][j];
            p2[i][j] = p2[i-1][j] + p2[i][j-1] - p2[i-1][j-1] + d[i][j];
            p3[i][j] = p3[i-1][j] + p3[i][j-1] - p3[i-1][j-1] + e[i][j];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int w,x,y,z;
        cin >> w >> x >>y >> z;
        int c1 = cost(w,x,y,z,p1);
        int c2 = cost(w,x,y,z-1,p2);
        int c3 = cost(w,x,y-1,z,p3);
        cout << c1 -c2 - c3 << endl;
    }

}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}