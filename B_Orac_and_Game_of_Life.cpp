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

int n,m,t;
vector<vector<int>>a;
vector<pair<int,int>>neigh(int i, int j){
    vector<pair<int,int>>res;
    if(i > 1)res.pb({i-1,j});
    if(i < n)res.pb({i+1,j});
    if(j > 1)res.pb({i,j-1});
    if(j < m)res.pb({i,j+1});
    return res;
}
void solve()
{
    cin >> n >> m >> t;
    a = vector<vector<int>>(n+1, vector<int>(m+1));
    for(int i = 1;i<=n;++i){
        string s;
        cin >> s;
        for(int j = 0;j<m;++j)a[i][j+1] = s[j]-'0';
    }
    vector<vector<int>>dist(n+1, vector<int>(m+1,1e18+1)), visited(n+1, vector<int>(m+1));
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            for(auto [x,y] : neigh(i,j)){
                if(a[x][y]==a[i][j]){
                    dist[i][j] = 0;
                    pq.push({0,i,j});
                    break;
                }
            }
        }
    }
    while(!pq.empty()){
        int i = pq.top()[1], j = pq.top()[2];
        pq.pop();
        if(visited[i][j])continue;
        visited[i][j] = 1;
        for(auto [x,y]:neigh(i,j)){
            int ne = dist[i][j]+abs(a[x][y]-a[i][j]);
            if(dist[i][j]+abs(a[x][y]-a[i][j]) < dist[x][y]){
                dist[x][y] = ne;
                pq.push({ne, x, y});
            }
        }
    }
    while(t--){
        int u,v,p;
        cin >> u >> v >> p;
        if(dist[u][v] == 1e18+1){
            cout << a[u][v] << endl;
            continue;
        }
        if(p <= dist[u][v]){
            cout << a[u][v] << endl;
            continue;
        }
        int turn = p-dist[u][v];
        if(turn % 2)cout << 1-a[u][v] << endl;
        else cout << a[u][v] << endl;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}