#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}


int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n){
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        val+="1";
      }
      else
      {
        val+="0";
      }
    }
    while(val.front()=='0'){
        val.erase(0,1);
    }
    return val;
}




void solve()
{
    int n,m;
    cin >>n >> m;
    int r,c;
    cin >> r >> c;
    r--;
    c--;
    int x,y;
    cin >> x >> y;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j)cin >> a[i][j];
    }
    vector<vector<pair<int,int>>>dist(n, vector<pair<int,int>>(m,{1e18,1e18}));
    dist[r][c] = {0,0};
    deque<pair<int,int>>q;
    q.push_front({r,c});
    vector<vector<bool>>visited(n, vector<bool>(m,0));
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop_front();
        if(visited[i][j])continue;
        visited[i][j] = 1;
        if(i > 0){
            // i-1, j is a neighbour
            if (a[i - 1][j] != '*'){

                int curr_dist = dist[i-1][j].first+dist[i-1][j].second;
                int new_dist = dist[i][j].first+dist[i][j].second;
                if(new_dist < curr_dist){
                    q.push_front({i-1,j});
                    dist[i-1][j] = dist[i][j];
                }
            }
        }
        if(i<n-1){
            if(a[i+1][j]!='*'){
                int curr_dist = dist[i + 1][j].first+dist[i+1][j].second;
                int new_dist = dist[i][j].first+dist[i][j].second;
                if (new_dist < curr_dist)
                {
                    q.push_front({i + 1, j});
                    dist[i + 1][j] = dist[i][j];
                }
            }
        }
        if(j > 0){
            // i, j-1 is a neighbour
            if(a[i][j-1]!='*'){
                int curr_dist = dist[i][j-1].first+dist[i][j-1].second;
                int new_cost = dist[i][j].first+dist[i][j].second+1;
                if(new_cost < curr_dist){
                    dist[i][j-1] = {dist[i][j].first+1, dist[i][j].second};
                    q.push_back({i,j-1});
                }
            }
        }
        if(j<m-1){
            // i, j-1 is a neighbour
            if(a[i][j+1]=='*')continue;
            int curr_dist = dist[i][j+1].first+dist[i][j+1].second;
            int new_cost = dist[i][j].first+dist[i][j].second+1;
            if(new_cost < curr_dist){
                dist[i][j+1] = {dist[i][j].first, dist[i][j].second+1};
                q.push_back({i,j+1});
            }
        }
    }
    int res = 0;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(dist[i][j].first<=x && dist[i][j].second<=y)res++;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        solve();
    }
}