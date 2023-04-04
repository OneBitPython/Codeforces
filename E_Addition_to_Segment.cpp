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
    int q;
 
    cin >> n >> q;
    vector<int>a(n);
    int sz = sqrt(n);
    vector<int>b(1e6);
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int l,r;
            int x;
            cin >> l >> r >> x;
            r--;
            int g1 = l/sz, g2 = r/sz;
            if(g1==g2){
                for(int i = l;i<=r;++i)a[i]+=x;
            }else{
                for(int i = g1+1;i<=g2-1;++i)b[i]+=x;
                for(int i = l;i<(g1+1)*sz;++i)a[i]+=x;
                for(int i = g2*sz;i<=r;++i)a[i]+=x;
            }
        }else{
            int x;
            cin >> x;
            cout << a[x] + b[x/sz] << endl;
        }
    }
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