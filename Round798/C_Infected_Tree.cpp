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



vector<vector<int>>adj;
vector<bool>visited;
vector<int>subtree, chained;


void dfs(int u){
    visited[u] = 1;
    subtree[u] = 1;
    chained[u] = (adj[u].size() == 3?1:0);
    if(u == 1){
        chained[u] = (adj[u].size() == 2 ? 1: 0);
    }
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs(v);
        subtree[u]+=subtree[v];
        chained[u]+=chained[v];
    }
}
void solve()
{   
    int n;
    cin >> n;
    subtree = vector<int>(n+1);
    chained = vector<int>(n+1);
    adj = vector<vector<int>>(n+1);
    visited = vector<bool>(n+1);
    for(int i = 0;i<n-1;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    int res = 0;
    priority_queue<pair<int,pair<int,int>>>pq;
    queue<int>q;
    q.push(1);
    visited = vector<bool>(n+1);
    vector<bool>skipped(n+1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        skipped[u] = 1;
        for(int v : adj[u]){
            if(visited[v])continue;
            pq.push({chained[v], {subtree[v]-1,v}});
        }
        while(!pq.empty()){
            if(skipped[pq.top().second.second])pq.pop();
            else break;
        }
        int node = 0;
        if(!pq.empty()){
            int sub = pq.top().second.first;
            node = pq.top().second.second;
            pq.pop();
            res+=sub;
            visited[u] = 1;
            if(u == node)continue;
        }
        for(int v : adj[u]){
            if(visited[v])continue;
            skipped[v] = 1;
            if(v == node)continue;
            q.push(v);
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}