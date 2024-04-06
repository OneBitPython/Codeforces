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
    // find last element in range [l,r] that is <= x
    int sz = 1;
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }
 
    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i,v );
        else set(2*x+2, m, rx, i, v);
        seg[x] =  min(seg[2*x+1],seg[2*x+2]);
    }
 
    void set(int i, int v){
        set(0,0,sz,i,v);
    }
 
    int sol(int x, int lx, int rx, int k, int l, int r){
        if(seg[x]>k)return -1;
        if(lx >= r || rx <= l)return -1;
        if(rx-lx==1)return lx;
        int m = (lx+rx)/2;
        int res = sol(2*x+2,m,rx,k,l,r);
        if(res==-1)res = sol(2*x+1,lx,m,k,l,r);
        return res;
    }
 
    int sol(int l, int r, int k){
        return sol(0,0,sz,k,l,r);
    }
};
struct segtree3{
    // find first element in range [l,r] that is <= x
    int sz = 1;
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }
 
    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i,v );
        else set(2*x+2, m, rx, i, v);
        seg[x] =  min(seg[2*x+1],seg[2*x+2]);
    }
 
    void set(int i, int v){
        set(0,0,sz,i,v);
    }
 
    int sol(int x, int lx, int rx, int k, int l, int r){
        if(seg[x]>k)return -1;
        if(lx >= r || rx <= l)return -1;
        if(rx-lx==1)return lx;
        int m = (lx+rx)/2;
        int res = sol(2*x+1,lx,m,k,l,r);
        if(res==-1)res = sol(2*x+2,m,rx,k,l,r);
        return res;
    }
 
    int sol(int l, int r, int k){
        return sol(0,0,sz,k,l,r);
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
 
    void upd(int x, int lx, int rx, int l, int r, int val){
        if(lazy[x]){
            seg[x]+=((rx-lx)*lazy[x]);
            if(rx - lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }
        if(rx <= l || lx >= r)return;
        if(lx >= l && rx <= r){
            seg[x]+=((rx-lx)*val);
            if(rx-lx > 1){
                lazy[2*x+1]+=val;
                lazy[2*x+2]+=val;
            }
            return;
        }
        int m = (lx+rx)/2;
        upd(2*x+1, lx, m, l, r, val);
        upd(2*x+2, m, rx, l, r, val);
        seg[x] = seg[2*x+1]+seg[2*x+2];
    }
 
    void upd(int l, int r, int val){
        upd(0,0,sz,l,r,val);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x]+=((rx-lx)*lazy[x]);
            if(rx-lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
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
int n;
int d(int u, int v){
    // distance to cyclically shift righ tfrom u to v
    if(u < v)return v-u;
    return n-u+v;
}
void solve()
{

    cin >> n;
    vector<int>a(n+1),pos(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i], pos[a[i]] = i;
    segtree right;
    segtree3 left;
    left.init(n+1);
    right.init(n+1);
    for(int i = 1;i<=n;++i)right.set(i,a[i]);
    for(int i = 1;i<=n;++i)left.set(i,a[i]);

    segtree2 res;
    res.init(n+1);
    for(int i = 1;i<=n;++i){
        if(a[i]==(n-1)){
            res.upd(1,n+1,n);
            continue;
        }
        if(pos[a[i]+1] > i){
            int x = right.sol(1,n+1,a[i]); // first position with complete prefix
            if(x < pos[a[i]+1]){
                int get = (pos[a[i]+1]-x)*(a[i]+1);
                res.upd(1,d(pos[a[i]+1],1)+1,get);
                if(right.sol(1,i,a[i])==-1){
                    res.upd(d(i,1)+1,n+1,get);
                }
            }else{
                int y = left.sol(pos[a[i]+1],n+1,a[i]);
                int move = d(y,1);
                int x = right.sol(1,i+1,a[i]);
                int get = (pos[a[i]+1]-x)*(a[i]+1);
                int turns = (n-pos[a[i]+1]-move+1);
                res.upd(move+1,move+1+turns,get);
            }   
        }else{
            int x = right.sol(i,n+1,a[i]) - i + 1;
            int kk = right.sol(1,i,a[i]);
            int move = d(i,1);
            if(kk!=-1)x = kk+move;
            // move everything till a[i] comes first place 
            if((pos[a[i]+1] + move) > x){
                int get = (pos[a[i]+1]+move - x)*(a[i]+1);
                res.upd(move+1,move+1+n-(pos[a[i]+1]+move) + 1,get);
            }else{
                int y = left.sol(pos[a[i]+1],n+1,a[i]);
                int move = d(y,1);
                int x = right.sol(1,i+1,a[i]);
                int get = (pos[a[i]+1]-x)*(a[i]+1);
                int turns = (n-pos[a[i]+1]-move+1);
                res.upd(move+1,move+1+turns,get);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;++i)ans = max(ans, res.sol(i,i+1));
    cout << ans << endl;
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