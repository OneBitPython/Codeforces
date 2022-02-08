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
    int n, k;
    cin >> n >> k;
    
    if(k == 1){
        cout << "YES" << endl;

        for(int i = 1;i<=n;++i){
            cout << i << endl;
        }
        return;
    }
    if(n%2){
        cout << "NO" << endl;return;
    }

    set<int> evens, odds;
    for(int i = 1;i<=n*k;++i){
        if(i%2)odds.insert(i);
        else evens.insert(i);
    }
    vector<vector<int>> res;
    
    for(int i = 0;i<n;i+=2){
        int sum =  0;
        vector<int>tmp;
        for(int j = 0;j<k;j++){
            int n_sum = sum;
            int values = j+1;
            
            for(auto x : evens){
                if((n_sum+x)%values == 0){
                    n_sum+=x;
                    sum+=x;
                    bool got = true;
                    for(int g = 0;k<tmp.size();++g){
                        n_sum-=tmp[g];
                        values--;
                        if(n_sum % values != 0){
                            got = false;
                            break;
                        }
                    }
                    if(got){
                        tmp.pb(x);
                        evens.erase(x);
                        break;
                    }else sum-=x;
                }
            }
        }
        if(tmp.size()!=k){
            cout << "NO" << endl;return;

        }
        res.pb(tmp);
    }

    for(int i = 0;i<n;i+=2){
        int sum =  0;
        vector<int>tmp;
        for(int j = 0;j<k;j++){
            int n_sum = sum;
            int values = j+1;
            
            for(auto x : odds){
                if((n_sum+x)%values == 0){
                    n_sum+=x;
                    sum+=x;
                    bool got = true;
                    for(int g = 0;k<tmp.size();++g){
                        n_sum-=tmp[g];
                        values--;
                        if(n_sum % values != 0){
                            got = false;
                            break;
                        }
                    }
                    if(got){
                        tmp.pb(x);
                        odds.erase(x);
                        break;
                    }else sum-=x;
                }
            }
        }
        if(tmp.size()!=k){
            cout << "NO" << endl;return;

        }
        res.pb(tmp);
    }
    cout << "YES"<<endl;
    for(auto x : res)output(x);
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