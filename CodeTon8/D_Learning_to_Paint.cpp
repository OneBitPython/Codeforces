#include <bits/stdc++.h>
using namespace std;

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

const int inf = -1e9;
struct segtree{
    int sz = 1;
    vector<int>lazy;
    vector<pair<int,int>>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2,{inf,0});
        lazy.resize(sz*2);
    }


    void upd(int x, int lx, int rx, int l, int r, int v, int mm = 0){
        if(lazy[x]!=0){
            seg[x].first += lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2]+= lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx<=r){
            seg[x].first += v;
            if(mm)seg[x].first = v;
            if(rx-lx > 1){
                lazy[2*x+1] += v;
                lazy[2*x+2] += v;
            }else seg[x].second = lx;
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        upd(2*x+1,lx,m,l,r,v,mm);
        upd(2*x+2,m,rx,l,r,v,mm);
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }

    void upd(int l, int r, int v, int mm = 0){
        upd(0,0,sz,l,r,v,mm);
    }


    pair<int,int> sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]!=0){
            seg[x].first += lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2]+= lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return {inf,0ll};
        int m = (lx+rx)/2;
        return max(sol(2*x+1,lx,m,l,r), sol(2*x+2,m,rx,l,r));
    }

    pair<int,int> sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
int n,k;
int L(int i){
    return (i*k)+1;
}
int R(int i){
    return (i+1)*k;
}
void solve()
{
    cin >> n >> k;
    vector<vector<int>>a(n+1, vector<int>(n+1));
    for(int i = 1;i<=n;++i){
        for(int j = i;j<=n;++j)cin >> a[i][j];
    }
    segtree st;
    st.init((n+2)*k);
    st.upd(1,2,0,1);
    for(int i =2;i<=k;++i)st.upd(i,i+1,inf,1);

    for(int i = 1;i<=n;++i){

        for(int j = (i-2);j>=0;--j){
            int l = L(j), r = R(j);
            st.upd(l,r+1,a[j+2][i]);
        }


        vector<pair<int,int>>idxs;
        for(int j = 1;j<=k;++j){
            pair<int,int>res = st.sol(1,R(i-1)+1);
            idxs.pb(res);
            st.upd(res.second,res.second+1,inf,1);
        }

        for(auto x : idxs)st.upd(x.second,x.second+1,x.first,1);
        idxs.pb({a[1][i],0ll});
        sort(all(idxs),greater<pair<int,int>>());

        int p = 0;
        for(int j = L(i);j<=R(i);++j){
            st.upd(j,j+1,idxs[p++].first,1);
        }
        for(int j = (i-2);j>=0;--j){
            int l = L(j), r = R(j);
            st.upd(l,r+1,-a[j+2][i]);
        }
        if(i==n){
            for(int j = 0;j<k;++j)cout << idxs[j].first << ' ';
            cout << endl;
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