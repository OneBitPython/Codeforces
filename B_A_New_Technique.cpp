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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rows, cols;
    for(int i = 0;i<n;++i){
        vector<int> row(m, 0);
        for(int i = 0;i<m;++i) cin >> row[i];
        rows.pb(row);
    }
    for(int i = 0;i<m;++i){
        vector<int> col(n,0);
        for(int i = 0;i<n;++i) cin >> col[i];
        cols.pb(col);
    }
    vector<vector<int>> res;
    vector<bool> visited(rows.size(), 0);
    for(auto col : cols){
        if(find(all(visited), 0) == visited.end())break;
        for(auto val : col){
            for(int i = 0;i<rows.size();++i){
                vector<int> row = rows[i];
                if(find(all(row), val)!=row.end()){
                    if(!visited[i]){
                        visited[i] = 1;
                        res.pb(row);
                        break;
                    }
                }
            }
        }
    
    }
    for(auto x : res)output(x);
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    read(T);
    while (T--)
    {
        solve();
    }
}