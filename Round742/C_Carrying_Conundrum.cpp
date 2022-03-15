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
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<pair<int,int>>> values(n);

    for(int i = n-1;i>=0;--i){
        int val = (s[i] - '0');
        bool carry = 1;
        if(i - 2 < 0)carry = 0;
        else{
            if(s[i-2] == '0')carry = 0;
        }
        for(int j = 0;j<=9;++j){
            for(int k = 0;k<=9;++k){
                int add = j+k;
                if(add >= 10){
                    if(carry){
                        if(add%10 == val){
                            values[i].pb({j,k});
                        }
                    }
                }else{
                    if(add == val)values[i].pb({j, k});
                }
            }
        }
    }
    int res = 1;
    for(int i = 0;i<values.size();++i){
        output(values[i]);
        cout<< endl;
        res*=(values[i].size());
    }
    int cnt = 0;
    for(int i = 0;i<values.size();++i){
        for(auto x : values[i]){
            if(x.first == 0)cnt++;
            if(x.second == 0)cnt++;
        }
    }
    cout << (res-(cnt*2)) << endl;
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