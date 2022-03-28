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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    vector<bool>prefix(n), suffix(n);
    int mex = 1;
    int max_ = 0;
    set<int>pref, suf;
    for(int i =0;i<n-1;++i){
        if(pref.count(a[i]) == 1)break;
        pref.insert(a[i]);
        while(pref.count(mex))mex++;
        max_ = max(max_, a[i]);
        if(mex-1 == max_)prefix[i] = 1;

    }
    mex = 1;
    max_ = 0;
    for(int i = n-1;i>=1;--i){
        if(suf.count(a[i]) == 1)break;
        suf.insert(a[i]);
        while(suf.count(mex))mex++;
        max_ = max(max_, a[i]);
        if(mex-1 == max_)suffix[i] = 1;

    }
    vector<pair<int,int>> res;
    for(int i = 0;i<n-1;++i){
        if(prefix[i] && suffix[i+1])res.pb({i+1, n-(i+1)});
    }
    cout << res.size() << endl;
    for(auto x : res){
        cout << x.first << ' ' << x.second << endl;
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
    read(T);
    while (T--)
    {
        solve();
    }
}