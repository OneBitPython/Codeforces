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
vector<int>sz, id;
int root(int x){
    if(x == id[x]){
        return x;
    }
    return id[x] = root(id[x]);
}
void merge(int u, int v, int &unconnected){
    u = root(u);
    v = root(v);
    if(u == v)return;
    if(sz[u] < sz[v])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
    unconnected--;
}


void solve()
{
    int n, m;
    cin >> n >> m;
    sz.resize(n);
    id.resize(n);
    for(int i = 0;i<n;++i){
        id[i] = i;
        sz[i] = 1;
    }
    int unconnected = n;
    for(int i = 0;i<m;++i){
        int u, v;
        cin >> u >> v;
        merge(u, v,unconnected);
        cout << unconnected << endl;
    }
}


int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T=1;
    // read(T);
    while (T--)
    {
        solve();
    }
}