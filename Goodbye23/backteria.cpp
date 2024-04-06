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
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int nxt(int x,int lx, int rx, int l, int r){
        if(rx <= l || lx >= r || seg[x]==0)return -1;

        if(rx-lx==1)return lx;

        int m = (lx+rx)/2;
        int res = nxt(2*x+1,lx,m,l,r);
        if(res==-1)res = nxt(2*x+2,m,rx,l,r);
        return res;
    }

    int nxt(int l, int r){
        return nxt(0,0,sz,l,r);
    }

    int bef(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r || seg[x]==0)return -1;

        if(rx-lx==1)return lx;

        int m = (lx+rx)/2;
        int res = bef(2*x+2,m,rx,l,r);
        if(res==-1)res = bef(2*x+1,lx,m,l,r);
        return res;
    }

    int bef(int l, int r){
        return bef(0,0,sz,l,r);
    }

};

struct segtree2{
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
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = (seg[2*x+1] + seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x,int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 0;
        if(lx >= l && rx <= r)return seg[x];

        int m = (lx+rx)/2;
        return sol(2*x+1,lx,m,l,r) + sol(2*x+2,m,rx,l,r);
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }

};
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int>a(n+1);
    for(int i  = 1;i<=n;++i)cin >> a[i];


    segtree st;
    st.init(n+1);
    for(int i = 1;i<=n;++i){
        if(a[i] > 0)st.set(i,1);
    }
    segtree2 st2;
    st2.init(n+1);
    for(int i = 1;i<=n;++i)st2.set(i,a[i]);

    while(q--){
        int t;
        cin >> t;

        if(t==0){
            int l,r,k;
            cin >>l >> r >> k;
            l++;r++;
            int fr = st.nxt(l,n+1);
            while(fr!=-1 && fr <= r){
                int curr = st2.sol(fr,fr+1)/k;
                st2.set(fr,curr);
                if(curr==0)st.set(fr,0);
                fr = st.nxt(fr+1,n+1);
            }
        }else if(t==1){
            int i,v;
            cin >> i >> v;
            i++;
            if(st2.sol(i,i+1)==0)st.set(i,1);
            st2.set(i,v);
        }else if(t==2){
            int l,r;
            cin >> l >> r;
            l++;r++;
            cout << st2.sol(l,r+1) << endl;
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
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}