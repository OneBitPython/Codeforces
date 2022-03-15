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

template <typename T>
void output(vector<vector<T>> &v){
    for(auto x : v){
        output(x);
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
    vector<vector<bool>> grid(n, vector<bool>(m, 0));
    for(int i = 0;i<n;++i){
        string s;
        cin >> s;
        for(int j = 0;j<m;++j){
            if(s[j] == '*')grid[i][j] = 1;
        }
    }
    vector<vector<int>> prefixes;
    for(int i = 0;i<n;++i){
        vector<int>prefix(m);
        prefix[0] = grid[i][0];
        for(int j =1;j<m;++j)prefix[j] = prefix[j-1]+grid[i][j];
        prefixes.pb(prefix);
    }
    int res = 0;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(grid[i][j]){
                res++;
                int val = 3;
                for(int k = i+1;k<n;++k){
                    int side = val/2;

                    int l = j-side;
                    int r = j+side;
                    if(l < 0 || r >= m){
                        break;
                    }
                    int sum = prefixes[k][r];
                    if(l-1 >= 0)sum-=prefixes[k][l-1];

                    // int side = val/2;
                    // int cnt = 0;
                    // for(int l = j-1;l>=0;--l){
                    //     if(cnt >= side)break;
                    //     if(grid[k][l])cnt++;
                    //     else break;
                    // }
                    // if(cnt < side){
                    //     break;
                    // }
                    // if(grid[k][j])cnt++;
                    // else break;
                    // for(int l = j+1;l<m;++l){
                    //     if(cnt>=(val))break;
                    //     if(grid[k][l])cnt++;
                    //     else break;
                    // }
                    if(sum == val)res++;
                    else break;
                    val+=2;
                }
            }
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
    read(T);
    while (T--)
    {
        solve();
    }
}