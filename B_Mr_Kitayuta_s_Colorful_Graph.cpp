#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

int sum()
{
    return 0;
}
template <typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n)
{
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
        if ((n & i) != 0)
        {
            val += "1";
        }
        else
        {
            val += "0";
        }
    }
    while (val.front() == '0')
    {
        val.erase(0, 1);
    }
    return val;
}

void print() { cout << endl; };
template <typename T, typename... Args>
void print(T one, Args... rest)
{
    cout << one << " ";
    print(rest...);
}

void read(){};
template <typename T, typename... Args>
void read(T &one, Args &...rest)
{
    cin >> one;
    read(rest...);
}

template <typename T>
void output(vector<T> &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
template <typename one, typename two>
void output(map<one, two> &mp)
{
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output(set<T> &s)
{
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
}
template <typename T, typename W>
void output(pair<T, W> &p)
{
    cout << p.first << " " << p.second << endl;
}
template <typename T, typename W>
void output(vector<pair<T, W>> &arr)
{
    for (auto x : arr)
    {
        cout << x.first << " " << x.second << endl;
    }
}
bool dfs(int u, int end, int color, vector<vector<pair<int, int>>> &adj, vector<bool>&visited,vector<int>&ans){
    ans.pb(u);
    visited[u] =true;
    if(u==end){
        return true;
    }
    for(auto neighbour : adj[u]){
        int v = neighbour.first;
        if(!visited[v]){
            if(neighbour.second == color){
                if(dfs(v, end, color, adj, visited,ans)){
                    return true;
                }
            }
        }
    }
    ans.pop_back();
    return false;

}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    set<int>colors;
    for(int i  =0;i<m;++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a,c});
        colors.insert(c);
    }
    int q;cin >> q;
    for(int i = 0;i<q;++i){
        int u, v;
        cin >> u >> v;
        vector<int>ans;
        int a = 0;
        for(auto color : colors){
            vector<bool> visited(n + 1, 0);

            if(dfs(u,v,color, adj, visited,ans)){
                a++;
            }
        }
        cout << a << endl;
    }
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}