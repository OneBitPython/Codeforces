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
    if(k==1){
        cout << "YES" << endl;
        for(int i = 1;i<=n;++i) cout << i << endl;
        return;
    }
    if(n%2 ){
        cout << "NO" << endl;return;
    }
    
    vector<int>even, odd;
    for(int i = 1;i<=n*k;++i){
        if(i%2)odd.pb(i);
        else even.pb(i);
    }
    int pos1 = 0, pos2 = 0;
    vector<vector<int>> res;
    for(int i = 0;i<n;++i){
        vector<int>tmp;
        if(i%2){
            for(int j = pos1;j<pos1+k;++j){
                tmp.pb(odd[j]);
            }
            pos1+=k;
        }else{
            for(int j = pos2;j<pos2+k;++j){
                tmp.pb(even[j]);
            }
            pos2+=k;
        }
        
        res.pb(tmp);
    }
    cout << "YES" << endl;
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