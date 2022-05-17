#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}


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

struct segtree{
    int sz = 1;
    vector<pair<int,int>>mins;
    void init(int n){
        while(sz < n)sz*=2;
        mins.resize(sz*2);
    }

    pair<int,int> merge(pair<int,int>&x, pair<int,int>&y){
        pair<int,int>res;
        if(x.first < y.first){
            return x;
        }else if(y.first < x.first){
            return y;
        }else{
            // x.first == y.first
            res.first = x.first;
            res.second = x.second+y.second;
            return res;
        }
    }

    void set(int x, int lx, int rx, int i, pair<int,int>v){
        if(rx - lx == 1){
            mins[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i< m )set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        mins[x] = merge(mins[2*x+1], mins[2*x+2]);
    }
    void set(int i, pair<int,int>v){
        set(0,0,sz,i,v);
    }

    pair<int,int> sum(int x, int lx, int rx, int l, int r){
        if(lx>=r || rx<=l)return {1e18,0};
        if(lx>=l && rx<=r)return mins[x];
        int m = (lx+rx)/2;
        pair<int,int>left = sum(2*x+1, lx, m, l, r), right = sum(2*x+2, m, rx, l, r);
        return merge(left, right);
    }

    pair<int,int> sum(int l, int r){
        return sum(0,0,sz,l,r);
    }
};


void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int>a(n);
    for(int &u : a)cin >> u;


    segtree st;
    st.init(n);
    for(int i = 0;i<n;++i)st.set(i,make_pair(a[i], 1ll));
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int i,v;
            cin >> i >> v;
            st.set(i,make_pair(v, 1ll));
        }else{
            int l,r;
            cin>> l >> r;
            auto res = st.sum(l,r);
            cout << res.first << ' ' << res.second << endl;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        solve();
    }
}