#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

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
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0;i<m;++i){
        int u, v;
        cin >>u >> v;
        adj[u].pb(v);

        adj[v].pb(u);
    }
    bool got = true;
    int c = 0, d = 0;
    for(int i =1;i<=n;++i){
        if(adj[i].size()==n-1){
            c++;
        }else if(adj[i].size()==1){
            d++;;
        }
    }
    if(c==1 && d==n-1){
        cout << "star topology" << endl;return;
    }
    bool has = true;
    for(int i = 1;i<=n;++i){
        if(adj[i].size()!=2){
            has=false;break;
        }
    }
    if(has){
        cout << "ring topology" << endl;return;
    }
    int got1 = 0, got2 = 0;
    for(int i = 1;i<=n;++i){
        if(adj[i].size()==1){
            got1++;
        }else if(adj[i].size()==2){
            got2++;
        }
    }
    if(got1 == 2 && got2 == n-2){
        cout << "bus topology" << endl;return;
    }
    cout << "unknown topology" << endl;
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}