#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

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
    string s;
    cin >>s;
    
    vector<char> arr;
    int b = 0, w = 0;
    for(char x : s){
        if(x == 'B') b++; 
        else w++;
        arr.pb(x);
    }
    vector<char> arr2 = arr;
    if(b == 0 || w == 0){
        cout << 0 << endl;return;
    }
    vector<int> res;
    //change all to B
    for(int i = 0;i<n-1;++i){
        if(arr[i] == 'W'){
            arr[i] = 'B';
            res.pb(i+1);
            arr[i+1] = (arr[i+1] == 'W'?'B':'W');
        }
    }
    set<char>v(all(arr));
    if(v.size() == 1){
        cout << res.size() << endl;
        output(res);
        return;
    }
    //change all to W;
    res.clear();
    for(int i = 0;i<n-1;++i){
        if(arr2[i] == 'B'){
            arr2[i] = 'W';
            res.pb(i+1);
            arr2[i+1] = (arr2[i+1] == 'W'?'B':'W');

        }
    }
    set<char> check(all(arr2));
    if(check.size() == 1){
        cout << res.size() << endl;
        output(res);
        return;
    }
    cout << -1 << endl;
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}