#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

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


void dfs(int u,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&taken,vector<int>&path){
    visited[u] = 1;
    if(adj[u].empty())return;
    for(int v : adj[u]){
        if(taken[u])continue;
        if(!visited[v]){
            taken[u] = 1;
            path.pb(v);
            dfs(v, adj, visited, taken,path);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    int root;
    for(int i = 1;i<=n;++i){
        int v;
        cin >> v;
        if(i == v)root = i;
        else{
            adj[v].pb(i);
        }
    }
    vector<pair<int,int>>dist(n+1); // stores vertex and dist
    dist[root] = {0,root};
    queue<int>q;
    q.push(root);
    vector<bool>visited2(n+1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited2[u])continue;
        visited2[u] = 1;
        for(int v : adj[u]){
            if(!visited2[v]){
                q.push(v);
                int d = dist[u].first+1;
                dist[v] = {d, v};
            }
        }
    }

    int cnt = 0;
    vector<bool>visited(n+1);
    vector<vector<int>>paths;
    sort(all(dist));
    for(int i = 1;i<=n;++i){
        int node = dist[i].second;
        if(visited[node])continue;
        vector<bool>taken(n+1);
        vector<int>path;
        path.pb(node);
        dfs(node,adj,visited,taken,path);
        paths.pb(path);
        cnt++;
    }
    cout << cnt << endl;
    for(auto x : paths){
        cout << x.size() << endl;
        for(auto y : x)cout << y<< ' ';
        cout << endl;
    }
    cout << endl;
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
        
        solve();
    }
}