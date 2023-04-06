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

int n,m;
vector<pair<int,int>>neighbours(int i, int j){
    vector<pair<int,int>>ne;
    if(i>1)ne.pb({i-1,j});
    if(i < n)ne.pb({i+1,j});
    if(j>1)ne.pb({i,j-1});
    if(j < m)ne.pb({i,j+1});
    return ne;
}

void solve()
{
    cin >> n >> m;
    vector<vector<char>>a(n+1,vector<char>(m+1));
    int x = 0,y = 0;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            cin >> a[i][j];
            if(a[i][j]=='L')x=i,y=j;
        }
    }
    queue<pair<int,int>>q;
    vector<vector<char>>b = a;
    b[x][y] = '+';
    q.push({x,y});
    vector<vector<set<pair<int,int>>>>visited(n+1,vector<set<pair<int,int>>>(m+1));
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        if(b[i][j]=='#')continue;
        vector<pair<int,int>>ne = neighbours(i,j);
        int c = 0;
        for(auto x : ne){
            if(b[x.first][x.second]=='.')c++;
        }
        if(c<=1 || b[i][j]=='+'){
            b[i][j]='+';

            for(auto &[u,v] : ne){
                if(visited[i][j].count({u,v}) || b[i][j]=='#')continue;
                visited[i][j].insert({u,v});
                if(b[u][v]=='+')continue;
                q.push({u,v});
            }
        }
    }   
    b[x][y]='L';
    for(int i= 1;i<=n;++i){
        for(int j = 1;j<=m;++j)cout << b[i][j];
        cout << endl;
    }
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