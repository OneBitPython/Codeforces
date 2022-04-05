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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a){
        cin >> u;
    }
    
    set<int>vals;
    vals.insert(a[0]);
    if(a[0] < 0){
        cout << -1 << endl;
        return;
    }
    vector<int>res;
    int i = 1;
    vector<int>curr;
    curr.pb(a[0]);
    while(i < n){
        if(a[i] < 0){
            if(vals.count(abs(a[i])) == 1)vals.erase(abs(a[i]));
            else{
                cout << -1 << endl;
                return;
            }
        }else{
            if(vals.count(a[i]) == 1){
                cout << -1 << endl;
                return;
            }else{
                vals.insert(a[i]);
            }
        }
        curr.pb(a[i]);
        if(vals.empty()){
            res.pb(i+1);
            map<int,int>cnt;
            for(auto x : curr){
                cnt[x]++;
                if(cnt[x] > 1){
                    cout << -1 << endl;
                    return;
                }
            }
            if(i+1 < n){vals.insert(a[i+1]);curr.pb(a[i+1]);}
            curr.clear();
            
            i+=2;

        }else i++;
        
    }
    
    if(res.empty()){
        cout << -1 << endl;
        return;
    }

    // cout << res.size() << endl;
    // cout << res[0] << ' ';
    vector<int>ans;
    ans.pb(res[0]);
    for(int i = 1;i<res.size();++i){
        ans.pb(res[i]-res[i-1]);
    }
    if(accumulate(all(ans), 0ll) == n){
        cout << ans.size() << endl;
        output(ans);
    }else cout << -1 << endl;
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