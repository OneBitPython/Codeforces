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
    vector<int>seg,lazy;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(lazy[x]!=0){
            seg[x]+=lazy[x];
            if(rx - lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
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
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    void rangeupdate(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]!=0){
            seg[x]+=lazy[x];
            if(rx - lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }

        if(lx >= l && rx <= r){
            seg[x]+=v;
            if(rx - lx > 1){
                lazy[2*x+1] += v;
                lazy[2*x+2]+=v;
            }
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        rangeupdate(2*x+1, lx, m, l, r, v);
        rangeupdate(2*x+2, m, rx, l, r, v);
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }

    void rangeupdate(int l, int r, int v){
        rangeupdate(0,0,sz,l,r,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]!=0){
            seg[x]+=lazy[x];
            if(rx - lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }

        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 1e18;
        int m = (lx+rx)/2;
        return min(sol(2*x+1, lx, m,l,r), sol(2*x+2, m, rx,l,r));
    }

    int sol(int l, int r){
        return sol(0,0,sz, l, r);
    }
};
int n;
int query(segtree &st){
    int l = 1, r = n+1;
    if(st.sol(1,n+1) >= 0)return -1;
    while(l +1 < r){
        int m = (l+r)/2;
        if(st.sol(m,r+1)<0)l = m;
        else r = m;
    }
    return l;
}
void solve()
{
    cin >> n;
    vector<vector<int>>queries(n+1);
    for(int i = 1;i<=n;++i){
        int p,t;
        cin >> p >> t;
        if(t==1){
            int x;
            cin >> x;
            queries[i] = {p,t,x};
        }else queries[i] = {p,t};
    }
    vector<int>c(n+1);
    for(int i = 1;i<=n;++i){
        vector<int>x = queries[i];
        if(x[1]==1)c[x[0]]=x[2];
        else c[x[0]]=-1;
    }
    int co = 0, cc = 0;
    segtree st;
    st.init(n+2);
    for(int i = n;i>=1;--i){
        if(c[i]==-1)cc++;
        else co++;
        if(c[i]==-1)st.set(i,1e18);
        else st.set(i,cc-co);
    }
    vector<int>res(n+1);
    
    res.back() = query(st);
    if(res.back()!=-1)res.back() = c[res.back()];
    for(int i = n;i>=2;--i){
        if(queries[i][1]==0){
            // pop() operatoni on queries[i][0]
            st.rangeupdate(1,queries[i][0],-1);
        }else{
            // push(queries[i][2]) operation on queries[i][0]
            st.rangeupdate(1,queries[i][0],1);
        }
        st.set(queries[i][0],1e18);
        res[i-1] = query(st);
        if(res[i-1]!=-1)res[i-1] = c[res[i-1]];
    }
    for(int i = 1;i<=n;++i)cout << res[i] << endl;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}