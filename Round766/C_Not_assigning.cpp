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
vector<vector<int>> adj;
vector<bool>visited;
map<pair<int,int>, int> ans;
int curr = 2;
void dfs(int u){
    visited[u]  = 1;
    for(int v : adj[u]){
        if(!visited[v]){
            curr = (curr==2?3:2);
            ans[{u, v}] = curr;
            ans[{v, u}] = curr;

            dfs(v);
        }
    }
}

void cleanup(){
    adj.clear();
    visited.clear();
    ans.clear();
}

void solve()
{
    int n;
    cin >> n;
    int m = n-1;
    adj.resize(n+1);
    visited.resize(n+1,0);
    vector<pair<int,int>> req;
    
    for(int i = 0;i<n-1;++i){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        req.pb({u, v});
    }
    int leaf;
    for(int i = 1;i<=n;++i){
        if(adj[i].size()==1)leaf  = i;
        if(adj[i].size() >= 3){
            cout << -1 << endl;
            cleanup();
            return;
        }
    }
    
    dfs(leaf);
    for(auto x : req)cout << ans[x] << ' ';
    cout << endl;
    cleanup();

}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    read(T);
    while (T--)
    {
        solve();
    }
}