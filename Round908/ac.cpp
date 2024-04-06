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
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }

    void reset(){
        for(int i = 0;i<seg.size();++i)seg[i] = 0;
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] = max(seg[x], v);
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x ,int lx, int rx ,int l, int r){
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 0;
        int m = (lx+rx)/2;
        return max(sol(2*x+1,lx,m,l,r), sol(2*x+2,m,rx,l,r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};


int give(vector<int>&a){
    int n = a.size()-1;
    vector<int>dp(n+1);
    for(int i = 1;i<=n;++i){
        dp[i] = 1;
        for(int j = i-1;j>=1;--j){
            if(a[j] < a[i])dp[i] = max(dp[i], dp[j]+1);
        }
    }
    return *max_element(all(dp));
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<int>b(m+1);
    for(int i = 1;i<=m;++i)cin >> b[i];
    int W = give(a);

    set<int>c(all(a));
    for(auto x : b)c.insert(x);

    map<int,int>coord,back;
    int g = 1;
    for(auto x : c)back[g] = x,coord[x] = g++;
    for(int i = 1;i<=n;++i)a[i] = coord[a[i]];
    for(int i = 1;i<=m;++i)b[i] = coord[b[i]];

    segtree st;
    st.init(g+5);
    vector<int>dp(n+1);
    int mx = 0;
    for(int i = n;i>=1;--i){
        dp[i] = st.sol(a[i]+1,g+3)+1;
        st.set(a[i],dp[i]);
        mx = max(mx, dp[i]);
    }
    int greatest = 0;
    for(int i = 1;i<=n;++i){
        if(dp[i] == mx)greatest = max(greatest, a[i]);
    }
    if(mx == 1){
        vector<int>res;
        
        for(int i = 1;i<=n;++i)res.pb(back[a[i]]);
        for(int i = 1;i<=m;++i)res.pb(back[b[i]]);
        sort(all(res),greater<int>());
        for(auto x : res)cout << x <<' ';
        cout << endl;
        return;
    }
    sort(b.begin()+1, b.end());
    int pos = 1;
    for(int i = m;i>=1;--i){
        if(b[i] >= greatest){

        }else{
            pos = i+1;
            break;
        }
    }

    st.reset();
    for(int i = 0;i<=n;++i)dp[i] = 0;

    for(int i = 1;i<=n;++i){
        dp[i] = st.sol(0,a[i])+1;
        st.set(a[i],dp[i]);
    }
    int least = 1e18, id = 1;
    for(int i = 1;i<=n;++i){
        if(dp[i]==mx){
            if(a[i] < least)least = a[i], id = i;
        }
    }


    vector<int>res;
    for(int i = m;i>=pos;--i)res.pb(back[b[i]]);
    pos--; // add people in B from position pos onwards

    for(int i =1;i<id;++i)res.pb(back[a[i]]);

    while(pos > 0 && b[pos] >= a[id]){
        res.pb(back[b[pos]]);
        pos--;
    }
    for(int i = id;i<=n;++i)res.pb(back[a[i]]);

    for(int i = pos;i>=1;--i)res.pb(back[b[i]]);

    for(auto x : res)cout << x << ' ';
    // assert(give(res)==W);
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