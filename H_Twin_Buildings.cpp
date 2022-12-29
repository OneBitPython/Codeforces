#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const long double PI=3.141592653589;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
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
        if(i < m)set(2*x+1,lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = max(seg[2*x+1],seg[2*x+2]);
    }
 
    void set(int i, int v){
        set(0,0,sz,i,v);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return -1e18;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return max(sol(2*x+1, lx, m, l, r),sol(2*x+2, m, rx, l, r));
    }
 
    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<pair<long double,long double>>a(n);
    for(int i = 0;i<n;++i)cin >> a[i].first >> a[i].second;
    long double res = 0;
    // try to build both on the same land
    /*
    A×2≤Li and B≤Wi, or
    A×2≤Wi and B≤Li, or
    A≤Li and B×2≤Wi, or
    A≤Wi and  B×2≤L
    */
    for(int i = 0;i<n;++i){
        res = max(res, (a[i].first/2)*a[i].second);
        res = max(res, (a[i].second/2)*a[i].first);
    }
    // put them on diff land
    sort(all(a));
    vector<long double>suff(n);
    suff.back() = a.back().second;
    for(int i = n-2;i>=0;--i)suff[i] = max(suff[i+1],a[i].second);
    for(int i = 0;i<n-1;++i){
        res = max(res, a[i].first*min(a[i].second,suff[i+1]));
    }
    sort(all(a),[&](auto one, auto two){
        return one.second < two.second;
    });


    segtree st;
    st.init(n);
    for(int i = 0;i<n;++i)st.set(i,a[i].first);

    for(int i = 0;i<n;++i){
        int l = -1, r = n;
        swap(a[i].first,a[i].second);
        long double x = a[i].second;
        
        if(i < n)a[i].second = a[i+1].second;
        else a[i].second = 1e18;
        while(l + 1 < r){
            int m = (l+r)/2;
            if(a[m].second >= x)r = m;
            else l = m;
        }
        if(r==n){
            a[i].second = x;
            swap(a[i].first,a[i].second);
            continue;
        }
        long double mx = 0;
        if(r <= i){
            mx = max(mx, (long double)st.sol(r,i));
            r = i+1;
        }
        mx = max(mx, (long double)st.sol(r,n));
        
        res = max(res, x*min(a[i].first,mx));
        a[i].second = x;
        
        swap(a[i].first,a[i].second);
    }
    sort(all(a));
    for(int i = 0;i<n;++i)st.set(i,a[i].second);

    for(int i = 0;i<n;++i){
        int l = -1, r = n;
        swap(a[i].first,a[i].second);
        long double x = a[i].first;
        if(i < n)a[i].first = a[i+1].first;
        else a[i].first = 1e18;
        while(l + 1 < r){
            int m = (l+r)/2;
            if(a[m].first >= x)r = m;
            else l = m;
        }
        if(r==n){
            a[i].first = x;
            swap(a[i].first,a[i].second);
            continue;
        }
        long double mx = 0;
        if(r <= i){
            mx = max(mx, (long double)st.sol(r,i));
            r = i+1;
        }
        
        mx = max(mx, (long double)st.sol(r,n));
        res = max(res, x*min(a[i].second,mx));
        a[i].first = x;
        
        swap(a[i].first,a[i].second);
    }
    cout << fixed << setprecision(1) << res << endl;
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