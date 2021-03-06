#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()
#define endl '\n'
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

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

template<typename T>
void output_vec(vector<T> &v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}
template<typename one,typename two>
void output_map(map<one,two> &mp){
    for(auto itr= mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output_set(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}
void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> a;
    for(int i=0;i<n;++i){
        int x; cin >> x;
        vector<int>tmp(x); 
        for(int j=0;j<x;++j){
            cin >> tmp[j];
        }
        a.pb(tmp);
    }

    vector<pair<int,int>> res;
    for(auto x : a){
        int val = INT_MIN;
        for(int i = 0;i<x.size();++i){
            int v = x[i] - i;
            val = max(v, val);

        }
        res.pb({val, x.size()});

    }
    sort(all(res), [&](auto one, auto two){
        return one.first < two.first;
    });
    vector<int> res2;
    int sub = 0;
    for(int i = 0;i<res.size();++i){
        int new_val = res[i].first - sub;
        sub += res[i].second;
        res2.pb(new_val);
    }
    cout << *max_element(all(res2))+1 << endl;
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    read(T);
    while (T--)
    {
        solve();
    }
}