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

bool pos(int x, vector<int>curr, int k){
    int n = curr.size();
    int total = 0;
    for(int i = n-1;i>=0;--i){
        if(x==0)break;
        if(curr[i] > x)continue;
        int take = x/curr[i];
        x-=(curr[i] * take);
        total+=(take);
    }
    if(total <= k)return false;
    else return true;
}

void solve()
{
    int n, k;
    cin >> n >>k;
    vector<int> curr(n);
    for(int i = 0;i<n;++i){
        int v;
        cin >> v;
        curr[i] = (pow(10, v));
    }
    sort(all(curr));
    if(curr.front() != 1){
        cout << 1 << endl;
        return;
    }
    vector<int> dp(n);
    for(int i = 0;i<n-1;++i){
        int big = curr[i+1];
        int small = curr[i];
        dp[i] = (big-small)/small;
    }
    int total_used = 0;
    int res = 0;
    k++;
    for(int i = 0;i<n-1;++i){
        if(total_used+dp[i] <= k){
            total_used+=dp[i];
            res+=(curr[i] * dp[i]);
        }else{
            int rem = k - total_used;
            res+=(rem * curr[i]);
            cout << res << endl;
            return;
        }
    }
    int rem = k - total_used;
    res+=(curr.back() * rem);
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