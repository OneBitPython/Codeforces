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
vector<pair<int,int>>shift = {
    {1,2},
    {2,1},
    {-1,-2},
    {-2,-1},
    {1,-2},
    {2,-1},
    {-1,2},
    {-2,1}
};
set<pair<int,int>>get_neighbours(int i, int j){
    set<pair<int,int>>dist;
    for(auto x : shift){
        int xc = i+x.first, yc = j+x.second;
        if(xc >= 1 && xc <= n && yc >= 1 && yc <= m)dist.insert({xc,yc});
    }
    return dist;
}
void solve()
{
    cin >> n >> m;
    
    vector<vector<int>>visited(n+1,vector<int>(m+1));
    int ans = 0;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            if(visited[i][j])continue;
            queue<vector<int>>q;
            q.push({1,i,j});
            int res = 0, res1 = 0;
            while(!q.empty()){
                int t = q.front()[0], i = q.front()[1], j = q.front()[2];
                q.pop();
                if(visited[i][j])continue;
                visited[i][j] = 1;
                res+=t;
                res1+=!t;
                set<pair<int,int>>dist = get_neighbours(i,j);
                for(auto x : dist){
                    q.push({1-t,x.first,x.second});
                }
            }
            ans+=max(res,res1);
        }
    }
    cout << ans;
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