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
    vector<int>mx,mn;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        mx.resize(sz*2);
        mn.resize(sz*2);
    }
    
    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            mx[x] = v;
            mn[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);

        mn[x] = min(mn[2*x+1],mn[2*x+2]);
        mx[x] = max(mx[2*x+1],mx[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol1(int x, int lx, int rx, int l, int r){
        if(lx >= r || rx <= l)return -1e18;
        if(lx >= l && rx <= r)return mx[x];
        int m = (lx+rx)/2;
        return max(sol1(2*x+1,lx,m,l,r),sol1(2*x+2,m,rx,l,r));
    }

    int sol2(int x, int lx, int rx, int l, int r){
        if(lx >= r || rx <= l)return 1e18;
        if(lx >= l && rx <= r)return mn[x];
        int m = (lx+rx)/2;
        return min(sol2(2*x+1,lx,m,l,r),sol2(2*x+2,m,rx,l,r));
    }

    int rangemax(int l, int r){
        return sol1(0,0,sz,l,r);
    }
    
    int rangemin(int l, int r){
        return sol2(0,0,sz,l,r);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    stack<int>st;
    vector<int>ngl(n+1),ngr(n+1); // next greatest value to the left
    for(int i = 1;i<=n;++i){
        while(!st.empty() && a[st.top()] <= a[i]){
            st.pop();
        }
        if(st.empty())ngl[i] = 0;
        else ngl[i] = st.top();
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i = n;i>=1;--i){
        while(!st.empty() && a[st.top()] <= a[i])st.pop();
        if(st.empty())ngr[i] = n+1;
        else ngr[i] =st.top();
        st.push(i);
    }
    vector<int>pref(n+1);
    for(int i = 1;i<=n;++i)pref[i] = pref[i-1]+a[i];

    {
    segtree st;
    st.init(n+1);
    for(int i =1;i<=n;++i)st.set(i,pref[i]);
    for(int i= 1;i<=n;++i){
        // assume that a[i] is the max value. It goes to the left as long as no value is greater and goes to the right as long as no value is greater
        
        // try to make sum > a[i]
        // sum will be maximized when you do take
        int mx = st.rangemax(i,ngr[i]);
        int mn = st.rangemin(ngl[i],i);
        if((mx-mn) > a[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}