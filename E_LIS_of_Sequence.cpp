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
 
    void set(int x, int lx, int rx, int i, int v){
        if(rx - lx == 1){
            seg[x] = max(seg[x], v);
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }
 
    void set(int i, int v){
        set(0,0,sz,i,v);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(lx >= r || rx <= l)return 0ll;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return max(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }
 
    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin>> u;
    vector<int>dp(n,1),in(n);
    vector<vector<int>>adj(n);
    int lis = 1;
    segtree st;
    st.init(1e5+10);
    vector<set<pair<int,int>>>g(n+1);
    for(int i = 0;i<n;++i){
        dp[i] = st.sol(1ll,a[i])+1;
        st.set(a[i],dp[i]);
        // g[dp[i]].insert({a[i],i});
        // for(auto x : g[dp[i]-1]){
        //     if(x.first < a[i]){
        //         adj[i].pb(x.second);
        //         in[x.second]++;
        //     }
        //     else break;
        // }
        lis = max(lis, dp[i]);
    }
    vector<int>imp(n);
    for(int i = 0;i<n;++i){
        if(dp[i]==lis)imp[i] = 1;
    }
    vector<int>mx(n+1);
    for(int i = n-1;i>=0;--i){
        if(dp[i]==lis){
            mx[dp[i]] = max(mx[dp[i]],a[i]);
            continue;
        }
        if(a[i] < mx[dp[i]+1])imp[i] = 1;
        if(imp[i])mx[dp[i]] = max(mx[dp[i]],a[i]);
    }
    // queue<int>q;
    // vector<int>visited(n);
    // vector<int>imp(n); // imp[i] is this node part of LIS?
    // for(int i = 0;i<n;++i){
    //     if(in[i]==0)q.push(i);
    //     if(dp[i]==lis)imp[i] = 1;
    // }
    // while(!q.empty()){
    //     int u = q.front();
    //     q.pop();
    //     if(visited[u])continue;
    //     visited[u] = 1;
    //     for(int v : adj[u]){
    //         in[v]--;
    //         if(dp[v] == dp[u]-1)imp[v]= max(imp[v],imp[u]);
    //         if(in[v]==0)q.push(v);
    //     }
    // }
    vector<int>ans(n);
    vector<int>groups(n+1);
    for(int i = 0;i<n;++i){
        if(!imp[i])ans[i] = 1;
        else groups[dp[i]]++;
    }
    for(int i = 0;i<n;++i){
        if(imp[i]){
            if(groups[dp[i]]==1)ans[i] = 3;
            else ans[i] = 2;
        }
    }
    for(auto x : ans)cout << x;
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