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

void dfs(int i, vector<set<int>>&adj, string &res, vector<bool>&visited){
    visited[i] = 1;
    res+=(i+'a');
    for(int v : adj[i]){
        if(!visited[v])dfs(v,adj,res,visited);
    }
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<set<int>>adj(26);
    for(int i = 0;i<n-1;++i){
        adj[s[i]-'a'].insert(s[i+1]-'a');
        adj[s[i+1]-'a'].insert(s[i]-'a');
        if(s[i] == s[i+1]){
            cout << "NO" << endl;
            return;
        }
    }
    int ok = 0;
    for(int i = 0;i<26;++i){
        if(adj[i].size() > 2){
            cout << "NO" << endl;
            return;
        }

        if(adj[i].size() == 1)ok = 1;
    }
    if(!ok && n > 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<bool>visited(26);
    string res;
    for(int i = 0;i<26;++i){
        if(adj[i].size() > 1)continue;
        if(!visited[i]){
            dfs(i,adj,res, visited);
        }
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
    // #endif

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}