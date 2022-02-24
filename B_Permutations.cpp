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
    auto rearange = [&](string x, vector<int> order){
        vector<char> nums;
        int sz = order.size();
        for(auto v : x)nums.pb(v);

        int idx = sz-1;
        int res = 0;
        for(int i = 0;i<sz;++i){
            res+=(nums[order[i]]-'0')*(pow(10, idx));
            idx--;
        }
        return res;

    };

    int n, k;
    cin >> n >> k;
    vector<string> values(n);
    for(int i = 0;i<n;++i)cin >> values[i];
    
    vector<int> ks;
    for(int i = 0;i<k;++i)ks.pb(i);
    
    vector<int> new_arr;
    for(auto x : values){
        int ne = rearange(x, ks);
        new_arr.pb(ne);
    }
    int res = *max_element(all(new_arr)) - *min_element(all(new_arr));
    while(next_permutation(all(ks))){
        vector<int> new_arr;
        for(auto x : values){
            int ne = rearange(x, ks);
            new_arr.pb(ne);
        }
        int change = *max_element(all(new_arr)) - *min_element(all(new_arr));
        res = min(res, change);

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
    // read(T);
    while (T--)
    {
        solve();
    }
}