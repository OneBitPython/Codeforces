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
    vector<pair<int,int>>seg;
    vector<int>lazy;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    pair<int,int>merge(pair<int,int>a, pair<int,int>b){
        if(a.first < b.first)return a;
        if(a.first == b.first  && a.second < b.second)return a;
        return b;
    }

    void set(int x, int lx, int rx, int i, pair<int,int>v){
        if(rx-lx == 1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = merge(seg[2*x+1],seg[2*x+2]);
    }

    void set(int i,pair<int,int> v){
        set(0,0,sz,i,v);
    }

    pair<int,int> sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x].first+=lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return {1e18,0};
        int m = (lx+rx)/2;
        return merge(sol(2*x+1,lx,m,l,r),sol(2*x+2,m,rx,l,r));
    }

    pair<int,int> sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
    
    void upd(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]){
            seg[x].first+=lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r){
            seg[x].first += v;
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
        seg[x] = merge(seg[2*x+1],seg[2*x+2]);
    }

    void upd(int l, int r, int v){
        upd(0,0,sz,l,r,v);
    }
};

int summ(int a, int an){
    int n = abs(a-an)+1;
    return (n*(a+an))/2;
}
void solve()
{

    int n;
    cin>> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    segtree st;
    int res = 0,tot = 0,sum=0;
    st.init(n+1);
    for(int i = 1;i<=n;++i)st.set(i,{i,i});
    for(int i = 1;i<=n;++i){
        int x = a[i];
        
        tot++;
        sum+=x;
        st.upd(x,n+1,-1);
        pair<int,int>mn = st.sol(1,n+1);
        if(mn.first < 0){
            tot--;
            sum-=mn.second;
            st.upd(mn.second,n+1,1);
        }
        cout << sum-(tot*(tot+1))/2 << ' ';
    }
    cout << endl;
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