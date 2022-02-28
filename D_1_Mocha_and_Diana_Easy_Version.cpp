#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

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

void print(){cout << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cout << one << " ";
    print(rest...);
}

void output(map<int, pair<int,int>>&mp){
    for(auto itr=mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " - " << itr->second.first << " " << itr->second.second << endl;
    }
}

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

template<typename T>
void output(vector<T> &v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}
template<typename one,typename two>
void output(map<one,two> &mp){
    for(auto itr= mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}
template <typename T, typename W>
void output(pair<T, W>&p){
    cout << p.first << " " << p.second << endl;
}
template <typename T, typename W>
void output(vector<pair<T, W>> &arr){
    for(auto x : arr){
        cout << x.first << " " << x.second << endl;
    }
}

vector<int> id1, sz1, id2, sz2;
vector<vector<int>> adj1,adj2;
vector<bool>visited1,visited2;

int root(int u, vector<int> &id){
    if(u == id[u])return u;
    id[u] = root(id[u], id);
    return id[u];
}

bool same(int u, int v, vector<int> &id){
    u = root(u,id);
    v = root(v,id);
    return (v==u);
}

bool merge(int u, int v, vector<int>&id, vector<int>&sz){
    u = root(u,id);
    v = root(v,id);
    if(u == v)return false;
    if(sz[u] < sz[v])swap(u, v);
    id[v] = id[u];
    sz[u]+=sz[v];
    return true;
}

void dfs(int u, vector<bool>&visited, vector<int>&path, vector<vector<int>> &adj){
    visited[u] = 1;
    path.pb(u);
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v, visited, path,adj);
        }
    }
}

void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    id1.resize(n+1);
    sz1.resize(n+1);
    id2.resize(n+1);
    sz2.resize(n+1);
    adj1.resize(n+1);
    adj2.resize(n+1);
    visited1.resize(n+1);
    visited2.resize(n+1);


    for(int i = 0;i<m1;++i){
        int u, v;
        cin >> u >> v;
        adj1[u].pb(v);
        adj1[v].pb(u);

        
    }
    for(int i  =0;i<m2;++i){
        int u, v;
        cin >> u >> v;
        adj2[v].pb(u);
        adj2[u].pb(v);
    }
    for(int i = 1;i<=n;++i){
        id1[i] = i;
        id2[i] = i;
        sz1[i] = 1;
        sz2[i] = 1;
    }

    for(int i = 1;i<=n;++i){
        if(!visited1[i]){
            vector<int> path;
            dfs(i, visited1, path, adj1);
            for(int j = 0;j<path.size()-1;++j)merge(path[j], path[j+1], id1, sz1);
        }
    }
    for(int i = 1;i<=n;++i){
        if(!visited2[i]){
            vector<int> path;
            dfs(i, visited2, path, adj2);
            for(int j = 0;j<path.size()-1;++j)merge(path[j], path[j+1], id2, sz2);
        }
    }
    vector<pair<int,int>> res;
    for(int i = 1;i<=n;++i){
        for(int j = i+1;j<=n;++j){
            if(!same(i, j, id1) && !same(i, j, id2)){
                merge(i, j, id1, sz1);
                merge(i, j,id2, sz2);
                res.pb({i, j});
            }
        }
    }
    cout << res.size() << endl;
    output(res);
    
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // read(T);
    while (T--)
    {
        solve();
    }
}