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

bool f(vector<int>a, vector<int>b, vector<int>c,vector<vector<int>>&visited,vector<vector<char>>&d,int &t){
    if(visited[a[0]][a[1]] || visited[b[0]][b[1]] || visited[c[0]][c[1]])return 0;
    if(d[a[0]][a[1]] == '*' && d[b[0]][b[1]] == '*' && d[c[0]][c[1]] == '*'){
        visited[a[0]][a[1]] = t;
        visited[b[0]][b[1]] = t;
        visited[c[0]][c[1]] = t;
        t++;
        return 1;
    }
    return 0;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>>a(n+2, vector<char>(m+2));
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j)cin >> a[i][j];
    }
    vector<vector<int>>visited(n+2, vector<int>(m+2));
    int t = 1;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            if(visited[i][j])continue;
            if(a[i][j] != '*')continue;
            if(f({i,j}, {i+1,j}, {i,j+1},visited,a,t))continue;
            if(f({i,j}, {i+1,j}, {i,j-1},visited,a,t))continue;
            if(f({i,j}, {i-1,j}, {i,j+1},visited,a,t))continue;
            if(f({i,j}, {i-1,j}, {i,j-1},visited,a,t))continue;

            
        }
    }
    
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            if(a[i][j] == '*' && !visited[i][j]){
                cout << "NO" << endl;
                return;
            }
            if(!visited[i][j])continue;
            if(visited[i][j] && visited[i+1][j] && (visited[i][j]!=visited[i+1][j])){
                cout << "NO" << endl;
                return;
            }
            if(visited[i][j] && visited[i][j+1] && (visited[i][j]!=visited[i][j+1])){
                cout << "NO" << endl;
                return;
            }
        }
    }
    
    for(int i = 1;i<n;++i){
        for(int j = 1;j<m;++j){
            if(a[i][j] == '*' && !visited[i][j]){
                cout << "NO" << endl;
                return;
            }
            if(!visited[i][j])continue;
            if((visited[i][j]!=visited[i+1][j+1] && visited[i+1][j+1]) || (visited[i][j]!=visited[i+1][j-1] && visited[i+1][j-1]) || (visited[i][j]!=visited[i-1][j+1] && visited[i-1][j+1]) || (visited[i][j]!=visited[i-1][j-1] && visited[i-1][j-1])){
                cout << "NO" << endl;
                return;
            }
        }
    }
    // for(auto x : visited){
    //     dbg(x);
    // }
    cout << "YES" << endl;
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