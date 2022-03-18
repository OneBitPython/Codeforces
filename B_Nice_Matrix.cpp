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
    vector<vector<int>> a(n, vector<int>(m));
    for(int i =  0;i<n;++i){
        for(int j = 0;j<m;++j) cin >> a[i][j];
    }
    int res = 0;
    for(int i = 0;i<n/2;++i){
        for(int j = 0;j<(m/2);++j){
            int el1 = a[i][j], el2 = a[i][m-j-1];
            int el3 = a[n-i-1][j], el4 = a[n-i-1][m-j-1];
            // set everything to el2
            int res1 = 0;
            res1+=(abs(el2 - el1));
            res1+=(abs(el2 - el3));
            res1+=(abs(el2 - el4));

            int res2 = 0;
            res2+=(abs(el1 - el2));
            res2+=(abs(el1 - el3));
            res2+=(abs(el1 - el4));
            
            int res3 = 0;
            res3+=(abs(el3 - el1));
            res3+=(abs(el3-el2));
            res3+=(abs(el4-el3));

            int res4 = 0;
            res4+=(abs(el4-el1));
            res4+=(abs(el4-el2));
            res4+=(abs(el4-el3));

            res+=(min({res1,res2, res3, res4}));

        }
    }
    if(m%2){
        vector<int>vals;
        for(int i = 0;i<n;++i){
            vals.pb(a[i][m/2]);
        }
        for(int i = 0;i<vals.size()/2;++i){
            res+=(abs(vals[i] - vals[n-i-1]));
        }
    }
    if(n%2){
        vector<int>vals;
        for(int i = 0;i<m;++i){
            vals.pb(a[n/2][i]);
        }
        for(int i = 0;i<vals.size()/2;++i)res+=(abs(vals[i] - vals[m-i-1]));
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