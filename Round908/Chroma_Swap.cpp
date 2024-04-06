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



void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1), cola(n+1), b(n+1), colb(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=n;++i)cin >> cola[i];
    for(int i = 1;i<=n;++i)cin >> b[i];
    for(int i = 1;i<=n;++i)cin >> colb[i];
    vector<vector<int>>vals(2*n+1,{0});
    for(int i = 1;i<=n;++i){
        vals[cola[i]].pb(a[i]);
        vals[colb[i]].pb(b[i]);
    }
    for(int i =1;i<=(2*n);++i){
        sort(all(vals[i]));
    }
    vector<int>last(2*n+1,1);
    vector<int>res(n+1,-1);

    for(int i = 1;i<=n;++i){
        bool got = 0;
        while(last[cola[i]] < vals[cola[i]].size() && vals[cola[i]][last[cola[i]]] >= res[i-1]){
            res[i] = vals[cola[i]][last[cola[i]]],last[cola[i]]++;
            got = 1;
            break;
        }
        if(!got){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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