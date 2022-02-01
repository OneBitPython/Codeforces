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
    vector<int> a(n), b(n), c(n);
    for(int i = 0;i<n-1;++i) cin >> a[i];
    for(int i = 0;i<n-1;++i) cin >> b[i];
    for(int i = 0;i<n;++i) cin >> c[i];
    vector<int>p1(n), p2(n);
    p1[0] = 0;
    p2[0] = 0;
    p1[1] = a[0];
    for(int i = 1;i<n-1;++i){
        p1[i+1] = p1[i]+a[i];
    }
    p2[1] = b[0];
    for(int i = 1;i<n-1;++i)p2[i+1] = p2[i]+b[i];
    
    vector<int> costs;
    for(int i = 0;i<n;++i){
        int c1 = p1[i];
        int c2 = p2[n-1]-p2[i];
        costs.pb(c1+c2+c[i]);
    }
    int best = 1e9;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
            if(i!=j){
                best = min(best, (costs[i]+costs[j]));
            }
        }
    }
    cout << best << endl;

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