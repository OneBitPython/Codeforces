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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n, -1));
    vector<int>og;
    for(int i = 0;i<n;++i){
        int v;
        cin >> v;
        a[i][i] = v;
        og.push_back(v);
    }
    for(int i = 0;i<n;++i){
        queue<pair<int,int>>q;
        int se = og[i];
        int j = i, k = i; // i and j
        bool got  = 0;
        if(k > 0){
            if(a[j][k-1]==-1){
                q.push({j, k-1});
                got = 1;
            }
        }
        if(!got){
            if(j<n-1)q.push({j+1, k});
        }
        
        int val = se-1;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            if(a[u.first][u.second] != -1)continue;
            if(val == 0)break;
            val--;
            a[u.first][u.second] = se;

            int j = u.first, k = u.second; // i and j
            pair<int,int>p1 = {j, k-1};
            if(k > 0 ){
                if(a[p1.first][p1.second] ==-1){
                    q.push(p1);
                    continue;
                }
            }
            pair<int,int>p2 = {j+1, k};
            if(j < n-1){
                if(a[p2.first][p2.second]!=-1)continue;
                q.push(p2);
            }
            
            

        }
    }
    // for(int i = 0;i<n;++i){
    //     int val = og[i];
    //     int se = og[i];
    //     val--;
        
    //     int w = i-1;
    //     for(;w>=0;--w){
    //         if(val == 0)break;
    //         if(a[i][w] != -1)break;
    //         val--;
    //         a[i][w] = se;
    //     }
    //     int j = i+1;
    //     for(;j<n;++j){
    //         if(val == 0)break;
    //         if(a[j][i] != -1)break;
    //         val--;
    //         a[j][i] = se;
    //     }
    //     for(int k = w-1;k>=0;--k){
    //         if(val == 0)break;
    //         if(a[j][k] != -1)break;
    //         val--;
    //         a[j][k] = se;
    //     }

    // }
    for(int i = 0;i<n;++i){
        for(int j = 0;j<i+1;++j){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
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