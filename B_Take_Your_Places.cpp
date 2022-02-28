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
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int>>evens, odds;
    int o = 0, e = 0;
    for(int i = 0;i<n;++i){
        int v;
        cin >> v;
        a[i] = v;
        if(v %2 ){o++;odds.push(i);}
        else {e++;evens.push(i);};

    }
    
    if(abs(o-e) > 1){
        cout << -1 << endl;
        return;
    }
    int res = 0;
    int pt1 = 0, pt2 = 0;
    if(!evens.empty())pt1 = evens.top();
    if(!odds.empty())pt2 = odds.top();
    print(pt2, pt1);
    for(int i = 0;i<n-1;++i){
        int p1 = 0, p2 = 0;
        if(a[i] % 2)p1 = 1;
        if(a[i+1] % 2)p2 = 1;
        if(p1 == p2){
            
            if(a[i] % 2){
                // searching for even number
                // next even number is pt1
                res+=abs(i-pt1);
                swap(a[i], a[pt1]);
                odds.push(pt1);
            }else {res+=abs(i-pt2);swap(a[i], a[pt2]);evens.push(pt2);}
        }
        while(odds.top() <= i && !odds.empty())odds.pop();
        while(evens.top() <= i && !evens.empty())evens.pop();

        while(a[odds.top()] %2 == 0 && !odds.empty())odds.pop();
        while(a[evens.top()] % 2 == 1 && !evens.empty())evens.pop();
        if(!odds.empty())pt2= odds.top();
        if(!evens.empty())pt1 = evens.top();
        print(pt2, pt1, res);
        output(a);
        cout << endl;
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