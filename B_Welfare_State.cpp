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
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    int q;
    cin >> q;
    vector<vector<int>>queries;
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int i,v;
            cin >> i >> v;
            queries.pb({t,i,v});
        }else{
            int x;
            cin >> x;
            queries.pb({t,x});
        }
    }
    int m = queries.size();
    int mx_x = 0;
    vector<bool>taken(n+1);
    for(int i = m-1;i>=0;--i){
        int t = queries[i][0];
        if(t==2){
            mx_x = max(mx_x, queries[i][1]);
        }else{
            int p = queries[i][1],x=queries[i][2];
            if(taken[p])continue;
            taken[p] = 1;
            a[p] = max(x,mx_x);
        }
    }
    for(int i =1;i<=n;++i){
        if(!taken[i])a[i] = max(a[i],mx_x);
    }
    for(int i = 1;i<=n;++i)cout << a[i] << ' ';
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}