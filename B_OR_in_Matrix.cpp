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
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 1)), b(n, vector<int>(m,0));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            cin>>b[i][j];
        }
    }
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(b[i][j] == 0){
                for(int k = 0;k<n;++k){
                    grid[k][j] = 0;

                }
                for(int k = 0;k<m;++k)grid[i][k] = 0;
            }
        }
    }
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(b[i][j] == 1){
                bool has = 0;
                for(int k = 0;k<n;++k){
                    if(grid[k][j] == 1)has = 1;
                }
                for(int k = 0;k<m;++k){
                    if(grid[i][k] == 1)has = 1;
                }
                if(!has){
                    cout << "NO" << endl;
                    return;
                }
            }else{
                bool has = 0;
                for(int k = 0;k<n;++k){
                    if(grid[k][j] == 1)has = 1;
                }
                for(int k = 0;k<m;++k){
                    if(grid[i][k] == 1)has = 1;
                }
                if(has){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    for(auto x : grid)output(x);
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