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

int give_min_end(vector<int>&a, vector<int>&b, int n){
    int diff = 1e15;
    for(int i = 0;i<n;++i){
        diff = min(diff, abs(a[i] - b[n-1]));
    }
    return diff;
}

int give_min_start(vector<int>&a, vector<int>&b, int n){
    int diff = 1e15;
    for(int i = 0;i<n;++i){
        diff = min(diff, abs(a[i] - b[0]));
    }
    return diff;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n),b(n);
    for(int &u : a)cin >> u;
    for(int &u : b)cin >> u;
    // c1 : connecting a[0] to b[0] and a[n-1] to b[n-1]
    int a1 = abs((a[0]-b[0]))+abs(a.back() - b.back());

    // c2 : connecting a[0]_b[n-1] and b[n-1]_a[0]
    int a2 = (abs(a[0]-b.back()))+(abs(a.back() - b[0]));

    // case 3:connecting a[0] b[0] and a[n]_b[i] and b[n]_a[i]
    int a3 = (abs(a[0] - b[0]));
    a3+=(give_min_end(a, b, n));
    a3+=(give_min_end(b,a,n));

    //c4 : connecting b[n-1]_a[n-1] and a[0]_b[i] and b[0]_a[i]
    int a4 = abs(b.back() - a.back());
    a4+=(give_min_start(a, b, n));
    a4+=(give_min_start(b,a,n));

    // c5: connecting a[0]_b[n-1] and b[0]_a[i] and a[n-1]_b[i]
    int a5 = (abs(a[0] - b.back()));
    a5+=(give_min_start(a,b, n));
    a5+=(give_min_end(b,a,n));

    //c6:connecting a[n-1]_b[0] and a[0]_b[i] and b[n-1]_a[i]
    int a6 =(abs(a.back() - b[0]));
    a6+=(give_min_start(b, a, n));
    a6+=(give_min_end(a,b,n));

    // c7: connecting a[0]_b[i] and a[n-1]_b[i] and b[0]_a[i] and b[n-1]_a[i]
    int a7 = give_min_start(b, a, n);
    a7+=(give_min_end(b, a, n));
    a7+=(give_min_start(a, b, n));
    a7+=(give_min_end(a, b, n));

    cout << min({a1,a2,a3,a4,a5,a6,a7}) << endl;

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