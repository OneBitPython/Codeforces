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
    int a, b, x;
    cin >> a >> b >> x;
    int c = min(a, b);
    int n = a+b;
    if(x == a+b-1){
        int turn;
        if(a<b){
            turn = 1;
            
        }else turn = 0;
        for(int i = 0;i<n;++i){
            if(turn)cout <<'1';
            else cout <<'0';
            turn = turn==1?0:1;
        }
        return;
    }
    int turn = 0;
    if(a <b)turn=1;
    else turn = 0;
    int c1 = 0, c0 = 0;
    for(int i = 0;i<x;++i){
        if(turn){cout <<'1';c1++;}
        else {cout <<'0';c0++;}
        if(i == x-1)break;
        turn = turn==1?0:1;
    }
    int rem1 = a-c0;
    int rem2 = b-c1;
    if(turn == 0){
        //continue with 0
        for(int i = 0;i<rem1;++i)cout <<'0';
        for(int i = 0;i<rem2;++i)cout <<'1';
    }else{
        for(int i = 0;i<rem2;++i)cout<<'1';
        for(int i = 0;i<rem1;++i)cout<<'0';
    }
    cout << endl;
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