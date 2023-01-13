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
    vector<int>seg,seg2;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        seg2.resize(sz*2);
    }
 
    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] = v;
            seg2[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = min(seg[2*x+1],seg[2*x+2]);
        seg2[x] = max(seg2[2*x+1], seg2[2*x+2]);
    }
 
    void set(int i, int v){
        set(0,0,sz,i,v);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 1e18;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return min(sol(2*x+1, lx, m, l, r),sol(2*x+2, m, rx, l, r));
    }
 
    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
    
    int mx(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return -1e18;
        if(lx >= l && rx <= r)return seg2[x];
        int m = (lx+rx)/2;
        return max(mx(2*x+1, lx, m, l, r),mx(2*x+2, m, rx, l, r));
    }
 
    int mx(int l, int r){
        return mx(0,0,sz,l,r);
    }

};

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<int>ngl(n+2), ngr(n+2);
    vector<int>pref(n+2);
    for(int i = 1;i<=n;++i)pref[i] = pref[i-1]+a[i];
    stack<int>st;
    
    for(int i = 1;i<=n;++i){
        while(!st.empty() && a[st.top()]<=a[i])st.pop();
        if(st.empty())ngl[i] = 0;
        else ngl[i] = st.top();
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i = n;i>=1;--i){
        while(!st.empty() && a[st.top()]<=a[i])st.pop();
        if(st.empty())ngr[i] = n+1;
        else ngr[i] = st.top();
        st.push(i);
    }
    segtree s;
    s.init(n+5);
    for(int i = 0;i<=n+1;++i)s.set(i,pref[i]);
    int res = 0;
    for(int i = 1;i<=n;++i){
        int first = pref[i]-s.sol(ngl[i],i);
        int second = s.mx(i,ngr[i])-pref[i];
        int val = first+second-a[i];
        res = max(res, val);
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}