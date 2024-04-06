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
    vector<int>lazy, seg;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    void upd(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]){
            seg[x] = max(seg[x], lazy[x]);
            if(rx-lx > 1){
                lazy[2*x+1] = max(lazy[2*x+1], lazy[x]);
                lazy[2*x+2] = max(lazy[2*x+2], lazy[x]);
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r){
            seg[x] = max(seg[x], v);
            if(rx-lx > 1){
                lazy[2*x+1] = max(lazy[2*x+1], v);
                lazy[2*x+2] = max(lazy[2*x+2], v);
            }
            return;
        }
        if(lx >= r || rx <= l)return;
        int m = (lx+rx)/2;
        upd(2*x+1,lx,m,l,r,v);
        upd(2*x+2,m,rx,l,r,v);
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }

    void upd(int l, int r, int v){
        upd(0,0,sz,l,r,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x] = max(seg[x], lazy[x]);
            if(rx-lx > 1){
                lazy[2*x+1] = max(lazy[2*x+1], lazy[x]);
                lazy[2*x+2] = max(lazy[2*x+2], lazy[x]);
            }
            lazy[x] = 0;
        }    
        if(lx >= l && rx <= r)return seg[x];
        if(rx <=l || lx >= r)return 0ll;
        int m = (lx+rx)/2;
        return max(sol(2*x+1,lx,m,l,r), sol(2*x+2,m,rx,l,r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
struct segtree2{
    vector<int>lazy, seg;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx == 1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x] = max(seg[x], lazy[x]);
            if(rx-lx > 1){
                lazy[2*x+1] = max(lazy[2*x+1], lazy[x]);
                lazy[2*x+2] = max(lazy[2*x+2], lazy[x]);
            }
            lazy[x] = 0;
        }    
        if(lx >= l && rx <= r)return seg[x];
        if(rx <=l || lx >= r)return 1e18;
        int m = (lx+rx)/2;
        return min(sol(2*x+1,lx,m,l,r), sol(2*x+2,m,rx,l,r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1), b(n+1);
    vector<pair<int,int>>bb(n+1);
    vector<vector<int>>vals(n+1);   

    segtree sta;
    segtree2 stb;
    sta.init(n+1);
    stb.init(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i],sta.upd(i,i+1,a[i]),vals[a[i]].pb(i);
    for(int i = 1;i<=n;++i)cin >> b[i],bb[i].first = b[i], bb[i].second = i,stb.set(i,b[i]);


    sort(all(bb));
    for(int i = 1;i<=n;++i){
        int pos = bb[i].second, st = bb[i].first;
        int curr = sta.sol(pos,pos+1);
        if(curr==b[pos])continue;
        if(curr > b[pos]){
            cout << "NO" << endl;
            return;
        }

        if(vals[b[pos]].empty()){
            cout << "NO" << endl;return;
        }
        auto xx = lower_bound(all(vals[b[pos]]), pos) ;
        bool got = 0;
        if(xx!=vals[b[pos]].begin()){
            xx--;
            int p = *xx;
            if(sta.sol(p,pos+1) <= b[pos]){
                if(stb.sol(p,pos+1) >= b[pos]){
                    got = 1;
                    sta.upd(p,pos+1,b[pos]);
                }
            }
        }

        if(!got){
            xx = lower_bound(all(vals[b[pos]]), pos);
            if(xx!=vals[b[pos]].end()){
                int p = *xx;
                if(sta.sol(pos,p+1) <= b[pos]){
                    if(stb.sol(pos,p+1) >= b[pos]){
                        got = 1;
                        sta.upd(pos,p+1,b[pos]);
                    }
                }
            }
        }
        if(!got){
            cout << "NO" << endl;
            return;
        }
    }
    bool ok = 1;
    for(int i = 1;i<=n;++i){
        if(sta.sol(i,i+1)!=b[i])ok = 0;
    }
    cout << (ok?"YES":"NO") << endl;
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