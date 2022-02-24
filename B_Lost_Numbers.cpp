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
    vector<int> pos = {4 , 8, 15, 16, 23, 42};
    vector<int> res(6);
    cout << "? 1 2" << endl;
    int resp;
    cin >> resp;
    for(auto x :pos){
        for(auto y : pos){
            if(y!=x){
                if(x*y == resp){
                    res[0] = x;
                    res[1] = y;
                }
            }
        }
    }
    cout << "? 2 3" << endl;
    cin >> resp;
    for(auto x : pos){
        if(x!=res[0]){
            if(res[0]*x == resp){
                swap(res[0], res[1]);
                res[2] = x;
            }
        }
    }
    for(auto x : pos){
        if(x!=res[1]){
            if(res[1]*x == resp){
                res[2] = x;
            }
        }
    }
    
    for(int i = 3;i<5;++i){
        cout << "? " << i << ' ' << i+1 << endl;
        cin >> resp;
        for(auto x : pos){
            if(x!=res[i-1]){
                if(res[i-1]*x == resp){
                    res[i] = x;
                    break;
                }
            }
        }
    }
    for(auto x : pos){
        if(find(all(res), x) == res.end()){
            res[5] = x;
            break;
        }
    }
    cout << "! ";
    output(res);
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
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