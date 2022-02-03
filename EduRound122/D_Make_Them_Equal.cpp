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

int N = 1001;
vector<int> d(N, N);
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for(int i = 0;i<n;++i) cin >> b[i];
    for(int i = 0;i<n;++i) cin >> c[i];
    
    int sum = (int)(accumulate(all(b), 0LL));
    k = min(k, sum);
    vector<int>dp(k+1, 0);
     for (int i = 0; i < n; ++i) {
      for (int j = k - d[b[i]]; j >= 0; j--) {
        dp[j + d[b[i]]] = max(dp[j + d[b[i]]], dp[j] + c[i]);
      }
    } 
    cout << *max_element(all(dp)) << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    d[1] = 0;
    for (int i = 1; i < N; ++i) {
    for (int x = 1; x <= i; ++x) {
        int j = i + i / x;
        if (j < N) d[j] = min(d[j], d[i] + 1);
    }
    }
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    read(T);
    while (T--)
    {
        solve();
    }
}