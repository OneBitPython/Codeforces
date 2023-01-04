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
struct segtree2{
    vector<int>seg, lazy;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }
 
    void set(int x, int lx, int rx, int i, int v){
        if(lazy[x]){
            seg[x]=((rx-lx)*lazy[x]);
            if(rx-lx > 1){
                lazy[2*x+1]=lazy[x];
                lazy[2*x+2]=lazy[x];
            }
            lazy[x] = 0;
        }
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = seg[2*x+1]+seg[2*x+2];
    }
 
    void set(int i, int v){
        set(0,0,sz,i,v);
    }
 
    void rangeupdates(int x, int lx, int rx, int l, int r, int val){
        if(lazy[x]){
            seg[x]=((rx-lx)*lazy[x]);
            if(rx - lx > 1){
                lazy[2*x+1]=lazy[x];
                lazy[2*x+2]=lazy[x];
            }
            lazy[x] = 0;
        }
        if(rx <= l || lx >= r)return;
        if(lx >= l && rx <= r){
            seg[x]=((rx-lx)*val);
            if(rx-lx > 1){
                lazy[2*x+1]=val;
                lazy[2*x+2]=val;
            }
            return;
        }
        int m = (lx+rx)/2;
        rangeupdates(2*x+1, lx, m, l, r, val);
        rangeupdates(2*x+2, m, rx, l, r, val);
        seg[x] = seg[2*x+1]+seg[2*x+2];
    }
 
    void rangeupdates(int l, int r, int val){
        rangeupdates(0,0,sz,l,r,val);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x]=((rx-lx)*lazy[x]);
            if(rx-lx > 1){
                lazy[2*x+1]=lazy[x];
                lazy[2*x+2]=lazy[x];
            }
            lazy[x] = 0;
        }
        if(rx <= l || lx >= r)return 0ll;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return sol(2*x+1, lx, m, l, r) + sol(2*x+2, m, rx, l, r);
    }
 
    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n),b(n);
    for(int i = 0;i<n;++i)cin >> a[i];
    for(int i = 0;i<n;++i)cin >> b[i];
    int m;
    cin >> m;
    vector<int>razors(m);
    for(int &u : razors)cin >> u;

    for(int i = 0;i<n;++i){
        if(a[i] < b[i]){
            cout << "NO" << endl;
            return;
        }
    }

    map<int,set<int>>pos;
    map<int,set<int>>add_later;
    for(int i = 0;i<n;++i){
        pos[b[i]].insert(i);
    }
    sort(all(razors),greater<int>());
    segtree st;
    st.init(n);
    segtree2 st2;
    st2.init(n);
    for(int i = 0;i<n;++i)st2.set(i,a[i]);
    for(int i = 0;i<n;++i){
        if(a[i]==b[i] && a[i]>razors[0])st.set(i,1);
    }
    set<int>d(all(b));
    for(int i = 0;i<m;++i){
        // go through all points of type b[i] in a
        set<int>&c = pos[razors[i]];
        while(!d.empty()){
            int x = *--d.end();
            if(x>razors[i]){
                for(auto y : pos[x])st.set(y,1);
                d.erase(--d.end());
            }else break;
        }
        if(c.empty())continue;
        vector<int>taken;
        while(!c.empty()){
            int x= *c.begin();
            int t = st2.sol(x,x+1);
            t = min(t,a[x]);
            if(t==b[x])c.erase(c.begin()),taken.pb(x);
            else break;
        }
        for(auto x : taken)st.set(x,1);

        if(c.empty())continue;
        int start = *c.begin();
        int e = start;

        while(!c.empty()){
            int x = *c.begin();
            if(st.sum(start,x+1)==0){
                e = x;
                taken.pb(x);
                c.erase(c.begin());
            }else break;
        }
        for(auto x : taken)st.set(x,1);
        
        st2.rangeupdates(start,e+1,razors[i]);
        // for(int i = 0;i<n;++i)cout << st2.sol(i,i+1) << ' ';
        // cout << endl;
    }
    for(int i = 0;i<n;++i){
        // cout << st2.sol(i,i+1) << ' ';
        int x = min(st2.sol(i,i+1),a[i]);
        if(x!=b[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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