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
    string s, t;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    vector<pair<char,int>> cnt1, cnt2;
    char v = s[0];
    int sz = 1;
    for(int i = 1;i<n;++i){
        if(s[i] == v)sz++;
        else{
            cnt1.pb({v, sz});
            v = s[i];
            sz = 1;
        }
    }
    if(sz > 0){
        cnt1.pb({v, sz});
    }
    v = t[0];
    sz = 1;
    for(int i = 1;i<m;++i){
        if(t[i] == v)sz++;
        else{
            cnt2.pb({v, sz});
            v = t[i];
            sz = 1;
        }
    }
    if(sz > 0){
        cnt2.pb({v, sz});
    }
    // output(cnt1);
    // print();
    // output(cnt2);
    if(cnt1.size()!=cnt2.size()){
        cout << "NO" << endl;
        return;
    }
    for(int i = 0;i<cnt1.size();++i){
        if(cnt1[i].first != cnt2[i].first){
            cout << "NO" << endl;
            return;
        }
        if(cnt1[i].second > cnt2[i].second){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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