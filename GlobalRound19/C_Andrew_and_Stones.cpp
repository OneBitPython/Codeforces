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
    for(int &u : a)cin >> u;
    int evens = 0, ones = 0, odds = 0;
    for(int i = 1;i<n-1;++i){
        if(a[i] == 1)ones++;
        else if(a[i]%2)odds++;
        else evens++;
    }
    if(ones>0 && evens == 0 && odds == 0){
        cout << -1 << endl;
        return;
    }
    if(evens == 0 && odds == 1 && ones == 0){
        cout << -1 << endl;
        return;
    }
    // dealing with ones
    int res = 0;
    bool sign = 0;
    if(ones > 0 && odds == 1)sign = 1;
    if(!sign){
        for(int i = 1;i<n-1;++i){
            if(a[i] %2 == 0){
                a[i]-=2;
                res++;
                break;
            }
        }
        
        res+=(ones);
    }
    vector<int>odd, even;
    for(int i = 1;i<n-1;++i){
        if(a[i]==1){
            if(sign)odd.pb(a[i]);
        }
        if(a[i]%2 && a[i]!=1)odd.pb(a[i]);
        else even.pb(a[i]);
    }
    for(auto x : even)res+=(x/2);
    odds = odd.size();

    if(odds == 1){
        // one of the even numbers added one stone to this heap
        int x = odd[0]+1;
        res+=(x/2);
    }else if (odds>=2){
        // we have more than odd value. It takes two moves to set two odd values to even numbers and then one extra move for each next odd value
        int x1 = odd[0]-1;
        int x2 = odd[1]-1;
        res+=2; // 2 moves to set them to x-1
        res+=(x1/2);
        res+=(x2/2);
        for(int i = 2;i<odd.size();++i){
            int x = odd[i]+1;
            res+=(x/2);
        }
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