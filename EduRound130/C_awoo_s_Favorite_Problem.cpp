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


// segtree to find the sum of a's in a range
struct segtree{
    int sz = 1;
    vector<int>sums;
    void init(int n){
        while(sz < n)sz*=2;
        sums.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx - lx == 1){
            sums[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }

    void set(int i, int v){
        set(0,0,sz, i, v);
    }

    int sum(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 0ll;
        if(lx >= l && rx <= r)return sums[x];
        int m = (lx+rx)/2;
        int left = sum(2*x+1, lx, m, l, r);
        int right = sum(2*x+2, m, rx, l, r);
        return left+right;
    }

    int sum(int l, int r){
        return sum(0,0,sz,l,r);
    }
};


void solve()
{
    int n;
    cin >> n;
    string g,t;
    cin >> g >> t;
    vector<char>s(all(g));
    segtree a,b;
    a.init(n);
    b.init(n);
    for(int i = 0;i<n;++i){
        
        if(s[i] == 'b')b.set(i, 1);
        if(s[i] == 'a')a.set(i, 1);
    }
    vector<int>bs, cs;
    for(int i = 0;i<n;++i){
        if(s[i] == 'b')bs.pb(i);
        if(s[i] == 'c')cs.pb(i);
    }
    for(int i = 0;i<n;++i){
        if(s[i] == t[i])continue;
        if(t[i] == 'a'){
            cout << "NO" << endl;
            return;
        }
        if(t[i] == 'b'){
            int next_b = upper_bound(all(bs), i) - bs.begin();
            if(next_b == bs.size()){
                cout << "NO" << endl;
                return;
            }
            next_b = bs[next_b];
            // find a's in the range
            int sum = a.sum(i, next_b);
            if(sum == next_b - i){
                // swap the a and b
                a.set(i, 0);
                a.set(next_b, 1);
                b.set(i, 1);
                b.set(next_b, 0);
                bs.erase(find(all(bs), next_b));
                swap(s[i], s[next_b]);
            }else{
                cout << "NO" << endl;
                return;
            }
        }else{
            int next_c = upper_bound(all(cs), i) - cs.begin();
            if(next_c == cs.size()){
                cout << "NO" << endl;
                return;
            }
            next_c = cs[next_c];
            // find a's in the range
            int sum = b.sum(i, next_c);
            if(sum == next_c - i){
                // swap the a and b
                b.set(i, 0);
                b.set(next_c, 1);
                cs.erase(find(all(cs), next_c));
                swap(s[i], s[next_c]);
            }else{
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}