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

int adj[41][41];
int dp1[1ll<<20], dp2[1ll<<20];
vector<string>curr,st;
vector<vector<string>>gs;
map<string,int>coord;

void erase_d(vector<string>&a){
    sort(all(a));
    a.erase(unique(all(a)),a.end());
}

void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<n;++i){
        int t;
        cin >> t;
        if(t==1){
            erase_d(curr);
            if(!curr.empty())gs.pb(curr);
            curr.clear();
        }else{
            string s;
            cin >> s;
            st.pb(s);
            curr.pb(s);
        }
    }
    int g = 0;
    erase_d(st);
    for(auto x : st){
        coord[x] = g;
        g++;
    }

    erase_d(curr);
    if(!curr.empty())gs.pb(curr);
    for(auto x : gs){
        for(auto y : x){
            for(auto z : x){
                adj[coord[y]][coord[z]] = 1;
            }
        }
    }
    
    // problem is to find the max independent set of the graph created
    // can use MITM to optimize from 2^40 to 2^20+2^20 
    int f = m/2, s = m-f;
    int res = 0;
    for(int i = 0;i<(1ll<<f);++i){
        // is it posible to create an independent set out of nodes in mask i?
        // if not then dp1[i] = 0
        bool ok = 1;
        for(int j = 0;j<f;++j){
            if(i&(1ll<<j)){
                for(int k = 0;k<f;++k){
                    if(i&(1ll<<k) && j!=k){
                        if(adj[j][k])ok = 0;
                    }
                }
                dp1[i] = max(dp1[i],dp1[i-(1ll<<j)]);
            }
        }
        if(ok)dp1[i] = __builtin_popcount(i);
        res = max(res, dp1[i]);
    }

    for(int i = 0;i<(1ll<<s);++i){
        // is it posible to create an independent set out of nodes in mask i?
        // if not then dp2[i] = 0
        bool ok = 1;
        for(int j = 0;j<s;++j){
            if(i&(1ll<<j)){
                for(int k = 0;k<s;++k){
                    if(i&(1ll<<k) && j!=k){
                        if(adj[j+f][k+f])ok = 0;
                    }
                }
                dp2[i] = max(dp2[i],dp2[i-(1ll<<j)]);
            }
        }
        if(ok)dp2[i] = __builtin_popcount(i);
        res = max(res, dp2[i]);
    }
    // merge both sides
    for(int i = 0;i<(1ll<<f);++i){
        if(!dp1[i])continue;
        int mask = (1ll<<s)-1;
        for(int j = 0;j<f;++j){
            if(i&(1ll<<j)){
                for(int k = 0;k<s;++k){
                    if(mask&(1ll<<k)){
                        if(adj[j][f+k])mask-=(1ll<<k);
                    }
                }
            }
        }
        res = max(res, dp1[i]+dp2[mask]);
    }
    cout << res;
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