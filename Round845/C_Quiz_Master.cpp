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


vector<int> fact(int x){
    vector<int>res;
    for(int i = 1;i*i<=x;++i){
        if((x%i)==0){
            res.pb(i);
            if(x/i != i)res.pb(x/i);
        }

    }
    return res;
}
 
struct segtree{
    int sz =1;
    vector<int>seg, lazy;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }
 
    void set(int x, int lx, int rx, int i, int v){
        if(lazy[x]){
            // carry on the updates to children as well
            seg[x]=0;
            if(rx - lx > 1){
                lazy[2*x+1]=1;
                lazy[2*x+2]=1;
            }
            lazy[x] = 0;
        }
        if(rx - lx == 1){
            // leaf
            seg[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }
 
    void set(int i, int v){
        set(0, 0, sz, i, v);
    }
 
    void rangeupdates(int x,int lx, int rx, int l, int r,int val){
 
        if(lazy[x]){
            // carry on the updates to children as well
            seg[x]=0;
            if(rx - lx > 1){
                lazy[2*x+1]=1;
                lazy[2*x+2]=1;
            }
            lazy[x] = 0;
        }
 
        if(rx <= l || lx>=r)return;
        if(lx >= l && rx<=r){
            seg[x]=0;
            if(rx - lx > 1){
                lazy[2*x+1]=1;
                lazy[2*x+2]=1;
            }
            return;
        }
        int m = (lx+rx)/2;
        rangeupdates(2*x+1, lx, m, l, r, val);
        rangeupdates(2*x+2, m, rx, l, r, val);
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }
 
    void rangeupdates(int l, int r, int val){
        // rangeupdates(0, 0, sz, l, r, val);
        for(auto &x : seg)x = 0;
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            // carry on the updates to children as well
            seg[x]=0;
            if(rx - lx > 1){
                lazy[2*x+1]=1;
                lazy[2*x+2]=1;
            }
            lazy[x] = 0;
        }
 
        if(lx>=r || rx<=l)return 1e18;
        if(lx>=l && rx<= r)return seg[x];
        int m = (lx+rx)/2;
        return min(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }
 
    int sol(int l, int r){
        return sol(0, 0, sz, l, r);
    }
};
segtree st;
int m;
bool pos(int w, vector<vector<int>>&factors, vector<int>&a){
    st.rangeupdates(0,m+1,0);
    // cout << st.sol(1,m+1) << ' ' << w << endl;
    int n = a.size();
    int pos = 0;
    // for(int i = 1;i<=m;++i){
    //     cout << st.sol(i,i+1) << ' ';
    // }
    // cout << endl;
    for(int i = 0;i<n;++i){
        while(pos < n){
            if(a[pos]-a[i] <= w){
                for(auto x : factors[pos]){
                    if(x <= m)st.set(x,1);
                }
                pos++;
            }else break;
        }
        if(st.sol(1,m+1)>0){
            return 1;
        }
        for(auto x : factors[i]){
            if(x <= m)st.set(x,-1);
        }
    }
    return 0;
}

void solve()
{
    int n;
    cin >> n >> m;
    set<int>b;
    st.init(m+2);
    for(int i = 0;i<n;++i){
        int c;
        cin >> c;
        b.insert(c);
    }
    vector<int>a(all(b));
    n = a.size();

    vector<vector<int>>factors(n);
    for(int i = 0;i<n;++i){
        factors[i] = fact(a[i]);
    }
    int l = 0, r = a.back()+5;
    // dbg(pos(3,factors, a, m));
    if(pos(0,factors,a)==1){
        cout << 0 << endl;
        return;
    }
    st.rangeupdates(0,m+1,0);

    if(pos(r,factors,a)==0){
        cout << -1 << endl;
        return;
    }
    int pos = 0;
    int res = 1e18;
    st.rangeupdates(0,m+1,0);
    for(int i = 0;i<n;++i){
        if(st.sol(1,m+1)>0){
            res = min(res, a[pos-1]-a[i]);
        }else{
            while(pos < n){
                for(auto x : factors[pos]){
                    if(x <= m)st.set(x,1);
                }
                if(st.sol(1,m+1)>0){
                    
                    res = min(res, a[pos]-a[i]);
                    pos++;
                    break;
                }
                pos++;
            }
        }
        for(auto x : factors[i]){
            if(x <= m)st.set(x,-1);
        }
    }
    cout << res << endl;
    // while(l+1 < r){
    //     int m = (l+r)/2;
    //     if(pos(m,factors,a))r = m;
    //     else l = m;
    // }
    // cout << r << endl;
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