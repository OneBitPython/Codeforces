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
int mxn = (1e5)+1;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> x(mxn);
    vector<vector<int>> y(mxn);
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            int v;
            cin >> v;
            x[v].pb(j);
            y[v].pb(i);
        }
    }
    int res = 0;
    for(int j = 1;j<x.size();++j){
        vector<int>xo = x[j];
        if(xo.empty())continue;
        sort(all(xo));
        vector<int>prefix(xo.size());
        prefix[0] = xo[0];
        for(int i = 1;i<xo.size();++i)prefix[i] = prefix[i-1]+xo[i];
        int sub = 0;
        for(int i = 0;i<xo.size();++i){
            int sum = prefix.back() - prefix[i];
            sub+=(sum - ((xo.size()-i-1)*xo[i]));
        }
        {
        vector<int>yo = y[j];
        sort(all(yo));
        vector<int>prefix(yo.size());
        prefix[0] = yo[0];
        for(int i = 1;i<yo.size();++i)prefix[i] = prefix[i-1]+yo[i];
        for(int i = 0;i<yo.size();++i){
            int sum = prefix.back() - prefix[i];
            sub+=(sum - ((yo.size()-i-1)*yo[i]));
        }
        }
        res+=sub;
        

    }
    cout<< res << endl;
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