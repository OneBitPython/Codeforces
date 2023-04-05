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
    vector<int>seg,lazymx,lazymn;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazymx.resize(sz*2,-1);
        lazymn.resize(sz*2,-1);
    }

    void upd(int x, int v, int mode){
        if(mode){
            // range max update
            if(lazymn[x]!=-1){
                if(v>=lazymn[x]){
                    if(seg[x]>=v)lazymn[x] = v,lazymx[x]=-1;
                    else  lazymn[x]=-1,lazymx[x]=v;
                }else{
                    if(seg[x]<=v)lazymn[x]=-1,lazymx[x]=v;
                }
            }else{
                if(lazymx[x]==-1)lazymx[x]=v;
                lazymx[x] = max(lazymx[x],v);
            }
        }else{
            // range min update
            if(lazymx[x]!=-1){
                if(v>=lazymx[x]){
                    if(seg[x]>lazymx[x])lazymx[x]=-1,lazymn[x]=v;
                }else{ 
                    if(seg[x]>=v)lazymn[x]=v,lazymx[x]=-1;
                    else lazymn[x]=-1,lazymx[x]=v;
                }
            }else{
                if(lazymn[x]==-1)lazymn[x]=v;
                lazymn[x] = min(lazymn[x],v);
            }
        }
    }

    void prop(int x, int lx, int rx){
        if(lazymn[x]!=-1){
            seg[x] = min(seg[x],lazymn[x]);
            if(rx-lx > 1){
                upd(2*x+1,lazymn[x],0);
                upd(2*x+2,lazymn[x],0);
            }
            lazymn[x]= -1;
            return;
        }
        if(lazymx[x]!=-1){
            seg[x] = max(seg[x],lazymx[x]);
            if(rx-lx > 1){
                upd(2*x+1,lazymx[x],1);
                upd(2*x+2,lazymx[x],1);
            }
            lazymx[x]= -1;
        }
    }

    void update(int x, int lx,int rx,int l, int r, int v, int mode){
        prop(x,lx,rx);
        if(lx >= l && rx <= r){
            if(mode){
                seg[x] = max(seg[x],v);
                if(rx-lx > 1){
                    upd(2*x+1,v,mode);
                    upd(2*x+2,v,mode);
                }
            }else{
                seg[x] = min(seg[x],v);
                if(rx-lx > 1){
                    upd(2*x+1,v,mode);
                    upd(2*x+2,v,mode);
                }
            }
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        update(2*x+1,lx,m,l,r,v,mode);
        update(2*x+2,m,rx,l,r,v,mode);
        seg[x] = max(seg[2*x+1],seg[2*x+2]);
    }

    void update(int l, int r, int v, int mode){
        update(0,0,sz,l,r,v,mode);
        dbg(seg,lazymn,lazymx);
    }

    int sol(int x, int lx, int rx, int l){
        prop(x,lx,rx);
        if(rx-lx==1)return seg[x];
        int m = (lx+rx)/2;
        if(l < m)return sol(2*x+1,lx,m,l);
        else return sol(2*x+2,m,rx,l);
    }

    int sol(int l){
        return sol(0,0,sz,l);
    }
};

void solve()
{
    int n,k;
    cin >> n >> k;
    segtree st;
    st.init(n);
    for(int i = 0;i<k;++i){
        int t;
        cin >> t;
        if(t==1){
            // range max update
            int l,r,v;
            cin >> l >> r >> v;
            st.update(l,r+1,v,1);
        }else{
            int l,r,v;
            cin >> l >> r >> v;
            st.update(l,r+1,v,0);
        }
    }
    for(int i = 0;i<n;++i)cout << st.sol(i) <<  endl;
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