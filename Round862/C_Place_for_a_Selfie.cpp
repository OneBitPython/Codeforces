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


int check(int b, int a, int c){
    int val = (b*b)-(4*a*c);
    return val < 0;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int>t(n+1);
    for(int i = 1;i<=n;++i)cin >> t[i];
    t[0] = -1e18;
    sort(t.begin()+1, t.end());
    
    for(int i = 1;i<=m;++i){
        int a,b,c;
        cin >>a >> b >> c;
        int d = lower_bound(all(t),b)-t.begin()-1;
        if(d>=1){
            if(check(b-t[d],a,c)){
                cout << "YES" << endl;
                cout << t[d] << endl;
                continue;
            }
        }
        auto k = lower_bound(all(t),b);
        if(k!=t.end()){
            if(check(b-(*k),a,c)){
                cout << "YES" << endl;
                cout << *k << endl;
                continue;
            }
        }
        cout << "NO" << endl;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}