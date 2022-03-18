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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int>pos;
    for(int i = 0;i<n;++i){
        if(s[i] == '1')pos.pb(i);
    }
    if(pos.size() == 0){
        int res = 0;
        for(int i = 0;i<n;i+=k+1){
            if(i>=n)break;
            res++;
        }
        cout << res << endl;
        return;
    }
    int res = 0;
    for(int i = pos[0];i>=0;i-=(k+1)){
         if(i<0)break;
         if(i+(k)<pos[0])res++;
    }
    for(int i = 0;i<pos.size()-1;++i){
        int space = pos[i+1] - pos[i] - 1;
        for(int j = pos[i+1];j>pos[i];j-=(k+1)){
            if(j<0)break;
            if(pos[i]+k < j && j+k < pos[i+1] && j>=0)res++;
        }
        // print(res);
    }
    for(int i = pos.back();i<n;i+=(k+1)){
        if(i > n)break;
        if(pos.back()+k < i)res++;
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