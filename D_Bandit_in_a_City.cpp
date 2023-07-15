#include <bits/stdc++.h>
using namespace std;
using namespace std;


#define super __int128

std::ostream& operator << (std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value<0?-value:value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            -- d;
            *d = "0123456789"[tmp%10];
            tmp/=10;
        }while(tmp!=0);
        if(value<0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer)-d;
        if (dest.rdbuf()->sputn(d,len)!=len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}


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

int n;
vector<vector<int>>adj;
vector<super>space;
vector<int>a;
bool ok = 1;
void dfs(int u,int p,  int x){
    if(!ok)return;
    if(adj[u].empty())space[u] = x;
    for(int v : adj[u]){
        if(v==p)continue;
        dfs(v,u,x);
        space[u]+=space[v];
    }
    if(a[u] > space[u])ok = 0;
    space[u]-=a[u];
}
bool pos(int x){
    space = vector<super>(n+1);
    ok = 1;
    dfs(1,-1,x);
    return ok;               
}
void solve()
{

    cin >> n;
    adj.resize(n+1);
    a.resize(n+1);
    space.resize(n+1);
    for(int i = 2;i<=n;++i){
        int p;
        cin >> p;
        adj[p].pb(i);
    }
    for(int i = 1;i<=n;++i)cin >> a[i];
    int l = 0, r = 1e15;
    int res = 1e18;
    while(l <= r){
        int m = (l+r)/2;
        if(pos(m))res = m, r = m-1;
        else l = m+1;
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