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
    vector<int>a(n+1), b(n+1),c(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=n;++i)cin >> b[i],c[i]=b[i],b[i]+=i;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    pq.push({0, n, n});
    vector<int>dist(n+1, 1e18);
    dist[n]= 0;
    vector<int>visited(n+1);
    int reach = n;
    vector<int>par(n+1);
    while(!pq.empty()){
        int u = pq.top()[1], o = pq.top()[2];
        pq.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(int i = max(0ll,reach-1);i>=0;--i){
            int mv = u-i;
            if(mv > a[u]){
                reach = min(reach, i+1);
                break;
            }
            int v = b[i],og=b[i]-c[i];
            int curr_dist = dist[v], new_dist = dist[u]+1;
            if(new_dist < curr_dist){
                pq.push({new_dist, v,og});
                dist[v] = new_dist;
                par[og] = o;
            }
        }
    }
    
    if(dist[0] == 1e18){
        cout << -1 << endl;
        return;
    }
    vector<int>res;
    int x = 0;
    while(x!=n){
        res.pb(x);
        x = par[x];
    }
    reverse(all(res));
    cout << res.size() << endl;
    for(auto x : res)cout << x << ' ';
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