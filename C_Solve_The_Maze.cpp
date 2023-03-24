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
vector<pair<int,int>>neigh(int i, int j){
    vector<pair<int,int>>neighbours;
    if(i > 1)neighbours.pb({i-1, j});
    if(i < n)neighbours.pb({i+1, j});
    if(j > 1)neighbours.pb({i, j-1});
    if(j < m)neighbours.pb({i, j+1});
    return neighbours;
}

void solve()
{
    cin >> n >> m;
    vector<vector<char>>a(n+1, vector<char>(m+1));
    bool got = 0;
    for(int i = 1;i<=n;++i){
        string s;
        cin >> s;
        for(int j = 1;j<=m;++j)a[i][j] = s[j-1],got|=(a[i][j]=='G');
    }
    if(!got){
        cout << "Yes" << endl;
        return;
    }
    for(int i =1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            if(a[i][j]!='B')continue;
            for(auto &[u,v] : neigh(i,j)){
                if(u==n && v == m){
                    cout << "No" << endl;
                    return;
                }
                if(a[u][v]=='.')a[u][v] = '#';
            }
        }   
    }
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>pq;
    pq.push({0,n, m});
    vector<vector<int>>dist(n+1, vector<int>(m+1, 1e18));
    dist[n][m] = 0;
    vector<vector<int>>visited(n+1, vector<int>(m+1));
    while(!pq.empty()){
        int u = pq.top()[1], v = pq.top()[2];
        pq.pop();
        if(visited[u][v])continue;
        visited[u][v] = 1;
        for(auto &[i,j]:neigh(u,v)){
            if(a[i][j]=='#')continue;
            int curr_dist = dist[i][j], new_dist = dist[u][v]+1;
            if(new_dist < curr_dist){
                pq.push({new_dist, i, j});
                dist[i][j] = new_dist;
            }
        }
    }
    bool ok = 1;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            if(a[i][j]=='G' && dist[i][j]>=1e18)ok = 0;
            if(a[i][j]=='B' && dist[i][j]<1e18)ok = 0;
        }
    }
    cout << (ok?"Yes":"No") << endl;
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