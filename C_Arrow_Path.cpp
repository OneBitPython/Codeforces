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

vector<vector<int>>a;
int n;
vector<pair<int,int>>neigh(int i, int j){
    vector<pair<int,int>>nn;
    if(j > 1)nn.pb({i,j-1});
    if(j < n)nn.pb({i,j+1});
    if(i==1)nn.pb({i+1,j});
    if(i == 2)nn.pb({i-1,j});
    return nn;
}
void solve()
{
    cin >> n;
    a = vector<vector<int>>(3,vector<int>(n+1));
    for(int i = 1;i<=2;++i){
        string s;
        cin >> s;
        for(int j = 0;j<n;++j){
            dbg(j,s[j],s);
            if(s[j]=='>')a[i][j+1]= 1;
        }
    }    

    queue<pair<int,int>>q;
    vector<vector<int>>vis(3,vector<int>(n+1));
    q.push({1,1});
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        if(vis[i][j])continue;
        vis[i][j] = 1;
        for(auto [x,y] : neigh(i,j)){
            if(a[x][y])y++;
            else y--;
            q.push({x,y});
        }
    }
    cout << (vis[2][n]?"YES":"NO") << endl;
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