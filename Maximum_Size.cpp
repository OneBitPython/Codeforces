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
    vector<vector<bool>> grid;
    for(int i = 0;i<n;++i){
        string s;
        cin >> s;
        vector<bool>tmp;
        for(int j = 0;j<m;++j){
            tmp.pb(s[j]-'0');
        }
        grid.pb(tmp);
    }
    
    vector<vector<bool>>visited(n, vector<bool>(m,0));
    vector<int>res;
    for(int x = 0;x<n;++x){
        for(int y = 0;y<m;++y){
            queue<pair<int,int>> q;
            q.push({x,y});
            int sz = 0;
            while(!q.empty()){
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(visited[i][j])continue;
                visited[i][j] = 1;
                if(grid[i][j] == 1){
                    sz++;
                    vector<pair<int,int>> neighbours;
                    if(i>0)neighbours.pb({i-1, j});
                    if(i<n-1)neighbours.pb({i+1, j});
                    if(j<m-1)neighbours.pb({i, j+1});
                    if(j > 0 )neighbours.pb({i, j-1});
                    for(auto v : neighbours){
                        if(!visited[v.first][v.second]){
                            q.push(v);
                        }
                    }
                }
            }
            if(sz > 0){
                res.pb(sz);
            }
        }
    }
    sort(all(res));
    reverse(all(res));
    int c = 0;
    for(int i = 1;i<res.size();i+=2)c+=res[i];
    cout << c << endl;
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