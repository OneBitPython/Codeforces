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

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

template<typename T>
void output_vec(vector<T> &v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}
template<typename one,typename two>
void output_map(map<one,two> &mp){
    for(auto itr= mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output_set(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}
bool isprime(int n){
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; (long long)i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

int solve2(vector<int>&a){
    int n = a.size();
    int prev = 0, next = 0;
    int sub = 0;
    for(int i = 0;i<n;++i){
        if(!isprime(a[i])){
            if(a[i] == 1)prev++;
            else prev = 0;
            continue;
        }
        // a[i] is prime
        int j = i+1;
        next = 0;
        for(;j<n;++j){
            if(a[j] == 1)next++;
            else break;
        }
        i = j-1;
        sub+=((prev+1)*(next+1))-1;
        prev = next;
    }
    // sub+=((prev+1)*(next+1))-1;
    return sub;

}

void solve()
{
    int n,e;
    read(n,e);
    vector<int> a(n);
    vector<int>prime_nums;
    for(int i = 0;i<n;++i){
        cin >> a[i];
        
    }
    int res = 0;
    for(int i = 0;i<e;++i){
        vector<int> curr;
        for(int j = i;j<n;j+=e){
            curr.pb(a[j]);
        }
        
        if(curr.empty())continue;
        // for(auto x : curr)cout << x << ' ';
        // cout << endl;
        res+= solve2(curr);
    }
    cout <<res << endl;
    
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    read(T);
    while (T--)
    {
        solve();
    }
}