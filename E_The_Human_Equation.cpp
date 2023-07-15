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
    // range min range add update
    vector<pair<int,int>>seg;
    vector<int>lazy;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, pair<int,int>v){
        if(rx-lx == 1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, pair<int,int>v){
        set(0,0,sz,i,v);
    }

    void upd(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]){
            seg[x].first+=lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r){
            seg[x].first+=v;
            if(rx-lx > 1){
                lazy[2*x+1]+=v;
                lazy[2*x+2]+=v;
            }
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        upd(2*x+1,lx,m,l,r,v);
        upd(2*x+2,m,rx,l,r,v);
        seg[x] = min(seg[2*x+1],seg[2*x+2]);
    }

    void upd(int l, int r, int v){
        upd(0,0,sz,l,r,v);
    }

    pair<int,int>sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x].first+=lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return {1e18,0};

        int m = (lx+rx)/2;
        return min(sol(2*x+1,lx,m,l,r),sol(2*x+2,m,rx,l,r));
    }

    pair<int,int>sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<int>b = {0};
    int sum = 0,p =0;
    if(a[1]<0)p = 1;
    for(int i = 1;i<=n;++i){
        if(a[i]==0)continue;
        if(!p){
            if(a[i]>0)sum+=a[i];
            else{
                if(sum!=0)b.pb(sum);
                sum = a[i];
                p = 1;
            }
        }else{
            if(a[i] < 0)sum+=a[i];
            else{
                if(sum!=0)b.pb(sum);
                sum = a[i];
                p = 0;
            }
        }
    }
    if(sum!=0)b.pb(sum);
    int m= b.size()-1;
    vector<int>pos(m+1);
    set<int>posi,negi;
    for(int i = 1;i<=m;++i){
        if(b[i]>0){
            posi.insert(i);
            pos[i] = 1;
        }else{
            negi.insert(i);
        }
    }   
    segtree st;
    st.init(m+1);
    for(int i = 1;i<=m;++i)st.set(i,{abs(b[i]),i});
    int res = 0;
    for(int i = 1;i<=m;++i){
        pair<int,int>val = st.sol(1,m+1);
        int idx = val.second, mn = val.first;
        if(mn>1e15)break;
        st.upd(1,m+1,-mn);

        res+=mn;
        st.upd(idx,idx+1,1e18);

        if(!pos[idx]){
            negi.erase(idx);
            if(!posi.empty() && idx > *posi.begin()){
                auto kk = --posi.lower_bound(idx);
                int bef = *kk;
                if(bef<(*(--posi.end()))){
                    int nxt = *posi.upper_bound(bef);
                    st.upd(bef,bef+1,st.sol(nxt,nxt+1).first);
                    st.upd(nxt,nxt+1,1e18);
                    posi.erase(nxt);
                }
            }
        }else{
            posi.erase(idx);
            if(!negi.empty() && idx > *negi.begin()){
                auto kk = --negi.lower_bound(idx);
                int bef = *kk;
                if(bef<(*(--negi.end()))){
                    int nxt = *negi.upper_bound(bef);
                    st.upd(bef,bef+1,st.sol(nxt,nxt+1).first);
                    st.upd(nxt,nxt+1,1e18);
                    negi.erase(nxt);
                }
            }
        }
    }
    cout << res << endl;
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