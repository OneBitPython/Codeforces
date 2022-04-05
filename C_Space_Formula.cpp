#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"
#define dbg(x) cerr << #x << " = " << x << endl;

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

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr <<  one << " ";
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
    int n, x;
    cin >> n >> x;
    x--;
    vector<int>points_before(n), awarded(n);
    for(int i = 0;i<n;++i)cin >> points_before[i];
    for(int i = 0;i<n;++i)cin >> awarded[i];
    int new_best = points_before[x] + awarded[0];

    awarded.erase(awarded.begin());
    sort(all(awarded));
    points_before.erase(points_before.begin()+x);
    vector<int>all_costs;
    for(int i = 0;i<n-1;++i){
        int req = new_best - points_before[i];
        int l = -1, r = awarded.size();
        while(l+1 < r){
            int m = (l+r)/2;
            if(awarded[m] <= req)l = m;
            else r = m;
        }
        if(l == -1){
            all_costs.pb(points_before[i]+awarded.back());
            awarded.erase(awarded.begin()+awarded.size()-1);
            
        }else{ 
            all_costs.pb(points_before[i]+awarded[l]);
            awarded.erase(awarded.begin()+l);
            
        }
    }
    int res = n;
    for(int i = 0;i<all_costs.size();++i){
        if(new_best >= all_costs[i])res--;
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