#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;


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

struct segtree{
    // add 1 to range
    // find first element >= x
    // keep track of max of each segment
    int sz = 1;
    vector<int>seg,lazy;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    void upd(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]!=0){
            seg[x] += lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r){
            seg[x] += v;
            if(rx-lx > 1){
                lazy[2*x+1] += v;
                lazy[2*x+2] += v;
            }
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        upd(2*x+1,lx,m,l,r,v);
        upd(2*x+2,m,rx,l,r,v);
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }

    void upd(int l, int r ,int v){
        upd(0,0,sz,l,r,v);
    }

    int sol(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]!=0){
            seg[x] += lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2] += lazy[x];
            }
            lazy[x] = 0;
        }    

        if(seg[x] < v)return -1;
        if(lx >= r || rx <= l)return -1;
        if(rx-lx == 1){
            return lx;
        }
        int m = (lx+rx)/2;
        int res = sol(2*x+1,lx,m,l,r,v);
        if(res!=-1)return res;
        return sol(2*x+2,m,rx,l,r,v);
    }

    int sol(int l, int r, int v){
        // first element >= v
        return sol(0,0,sz,l,r,v);
    }
};

struct segtree2{
    int size =1;
    vector<int> arr;
    void init(int n){
        while(size < n)size*=2;
        arr.resize(size*2, 0);
    }
 
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            arr[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m){
            set(i, v, 2*x+1, lx, m);
        }else{
            set(i, v, 2*x+2, m, rx);
        }
        arr[x] = arr[2*x+1]+arr[2*x+2];
    }
 
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
 
    int sum(int l, int r, int x, int lx, int rx){
        if(lx>=r || rx<=l)return 0;
        if(lx>=l && rx<=r)return arr[x];
        int m = (lx+rx)/2;
        int right = sum(l,r,2*x+2,m,rx);
        int left = sum(l,r,2*x+1,lx,m);
        return right+left;
    }
 
    int sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int>a(n+1);
    int sum = 0;
    for(int i = 1;i<=n;++i)cin >> a[i];
    segtree st;st.init(n+1);

    segtree2 st2;st2.init(n+1);

    for(int i = 1;i<=n;++i){
        sum+=a[i];
        st.upd(i,i+1,sum);
        st2.set(i,a[i]);
    }
    set<int>ones;
    for(int i = 1;i<=n;++i){
        if(a[i]==1)ones.insert(i);
    }
    while(q--){
        int t;cin >> t;
        if(t==1){
            int s;
            cin >> s;
            if(sum < s){
                cout << "NO" << endl;
                continue;
            }
            if(a[1]==1){
                cout << "YES" << endl;
                continue;;
            }
            int idx = st.sol(1,n+1,s);
            int sz = idx;
            if(st2.sum(1,idx+1) == s){
                cout << "YES" << endl;
                continue;
            }
            
            bool ok = 0;
            if(!ones.empty() && *(--ones.end()) > idx)ok = 1;
            if(!ok){
                if(!ones.empty()){
                    int pp = *(ones.begin());
                    if((n-pp+1) >= sz)ok = 1;
                }
            }
            cout << (ok?"YES":"NO") << endl;
        }else{
            int i,v;
            cin >> i >> v;
            if(a[i]==v)continue;

            if(a[i]==1)ones.erase(i);
            if(v==1)ones.insert(i);
            st.upd(i,n+1,(v-a[i]));
            st2.set(i,v);
            sum+=v;
            sum-=a[i];
            a[i] = v;
        }
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}