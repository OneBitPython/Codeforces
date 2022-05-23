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



int mod = 1e9+7;
int mpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1){
            res = ((res%mod)*(a%mod))%mod;
        }
        a = ((a%mod)*(a%mod))%mod;
        b>>=1;
    }
    return res;
}

struct segtree{
    int sz =1;
    vector<int>sums, lazy;
    void init(int n){
        while(sz < n)sz*=2;
        sums.resize(sz*2);
        lazy.resize(sz*2);
    }

    int merge(int x, int y){
        return ((x%mod)+(y%mod))%mod;
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx - lx == 1){
            sums[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*+x+2, m, rx, i, v);
        sums[x] = merge(sums[2*x+1], sums[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    void update(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            sums[x]/=2;
            if(rx-lx > 1){
                lazy[2*x+1] = 1;
                lazy[2*x+2] = 1;

            }
            lazy[x] = 0;
        }
        if(lx >=r || rx<=l)return;
        if(lx >= l && rx<=r){
            // complete intersection
            sums[x]/=2;
            if(rx- lx > 1){
                lazy[2*x+1] = 1;
                lazy[2*x+2] = 1;
            }
            return;
        }
        int m = (lx+rx)/2;
        update(2*x+1, lx, m, l, r);
        update(2*x+2, m, rx, l, r);
        sums[x] = merge(sums[2*x+1], sums[2*x+2]);
    }

    void update(int l, int r){
        update(0,0,sz,l,r);
    }

    int sum(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            sums[x]/=2;
            if(rx-lx > 1){
                lazy[2*x+1] = 1;
                lazy[2*x+2] = 1;

            }
            lazy[x] = 0;
        }
        if(lx>=r || rx<=l)return 0ll;
        if(lx >=l && rx<=r)return sums[x]%mod;

        int m = (lx+rx)/2;
        int left = sum(2*x+1, lx, m, l, r);
        int right = sum(2*x+2, m, rx, l, r);
        return merge(left, right);
    }

    int sum(int l, int r){
        return sum(0,0,sz,l,r);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    sort(all(a));
    segtree st;
    st.init(n);
    int tot = 0;
    int most_recent = 1;
    for(int i = 1;i<n;++i){
        int v = mpow(2,(i-1));
        most_recent= v;
        tot = ((tot%mod)+(v%mod))%mod;
        int s = ((v%mod)*(a[i]%mod))%mod;
        st.set(i, s);

    }
    int res = 0;
    for(int i = 0;i<n-1;++i){
        int fir = st.sum(i+1,n);
        int sec = ((a[i]%mod)*(tot%mod))%mod;
        if(sec>fir)swap(fir,sec);
        int c = ((((fir%mod)-(sec%mod))%mod)+mod)%mod;

        tot-=most_recent;
        most_recent/=2;
        if(i+2 < n)st.update(i+2, n);
        res = ((res%mod)+(c%mod))%mod;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        solve();
    }
}