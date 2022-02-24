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
struct segtree{
    int sz = 1;
    vector<int> res;
    map<pair<int,int>, int> sums;
    void init(int n){
        while(sz < n)sz*=2;
        res.resize(sz*2, 0);
    }
    
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            res[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m){
            set(i, v, 2*x+1, lx, m);
        }else{
            set(i, v, 2*x+2, m, rx);
        }
        res[x] =(res[2*x+1]^res[2*x+2]);
    }
    void set(int i, int v){

        set(i, v, 0, 0, sz);
        // output(res);
    }
    int sol(int l, int r, int x, int lx, int rx){
        if (lx>=r || rx<=l)
            return 0;
        if (lx >= l && rx <= r)
            return res[x];

        int m = (lx+rx)/2;
        int s1 = sol(l,r,2*x+1,lx, m);
        int s2 = sol(l,r,2*x+2, m, rx);
        return s1^s2;
    }
    int sol(int l, int r){
        if(sums.count(make_pair(l,r)) == 1){
            return sums[{l,r}];
        }
        int val = sol(l,r,0,0,sz);
        sums[{l,r}] = val;
        return val;
    }    
};
int mod = 4001;
void solve()
{
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    
    for(int i = 0;i<n;++i){
        int v;
        cin >> v;
        st.set(i, v);
    }
    for(int i = 0;i<m;++i){
        int t;
        cin >> t;
        if(t == 1){
            int j, v;
            cin >> j >> v;
            j--;
            st.set(j, v);
        }else{
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            int s = 0;
            for(int j = a;j<=b;++j){
                for(int k = j;k<=b;++k){
                    s = (s%mod + (st.sol(j, k+1)%mod))%mod;
                    // print(j, k+1);
                }
            }
            cout << s << endl;
            // return;
        }
    }
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