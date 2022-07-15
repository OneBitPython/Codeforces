#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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

const int mxn = 2e5+5;
vector<int> adj[mxn];
vector<int> vals[mxn];
bool bipartite(int u, vector<int>&color, int c){
    color[u] = c;
    for(int v : adj[u]){
        if(color[v]== -1){
            if(!bipartite(v, color, !c))return 0;
        }
        if(color[u] == color[v])return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>>p(n);
    for(int i = 0;i<n;++i){
        cin >> p[i].first >> p[i].second;
        vals[i].clear();
        adj[i].clear();
    }
    vals[n].clear();
    adj[n].clear();
    for(int i = 0;i<n;++i){
        vals[p[i].first].pb(i);
        vals[p[i].second].pb(i);
        if(vals[p[i].first].size() > 2 || vals[p[i].second].size() > 2 || p[i].first == p[i].second){
            cout << "NO" << endl;
            return;
        }
    }

    for(int i = 0;i<n;++i){
        int a = p[i].first, b = p[i].second;
        for(auto x : vals[a]){
            if(x!=i)adj[i].pb(x);
        }
        for(auto x : vals[b]){
            if(x!=i)adj[i].pb(x);
        }
    }
    vector<int>color(n+1,-1);
    for(int i = 0;i<n;++i){
        if(color[i] == -1){
            if (!bipartite(i, color, 0ll)){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}   
// 1,4 2,3 4,5 3,5
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