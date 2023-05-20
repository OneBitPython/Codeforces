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


int n,q;
vector<int>a;
bool pos(int x, int k){
    int doo = 0, get = 0;
    int perf = k;
    int opt = 0;
    for(int i = 1;i<=n;++i){
        if(a[i] < x){
            get++;
            if(perf<(x-a[i]))return 0;
            doo+=(perf-(x-a[i]));
            perf--;
        }else opt++,doo+=(a[i]-x);
    }
    int left = k-get;
    if(left%2){
        if(opt)doo+=(left);
    }
    if(left < 0)return 0;
    if(left%2){
        if(get==n)return 0;
    }
    bool ok = 0;
    if(doo < (left/2)){
        for(int i = get+1;i<=n;++i){
            doo-=(a[i]-x);
            doo+=(perf-(x-a[i]));
            perf--;
            left--;
            if(doo>=(left/2) && left%2){
                if(i<n)return 1;
                else return 0;
            }
            if(doo >= ((left+1)/2)){
                ok = 1;
                break;
            }
        }
    }else ok = 1;
    
    return ok;
}
void solve()
{
    cin >> n >> q;  
    a.resize(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    sort(a.begin()+1, a.end());
    while(q--){
        int k;
        cin >> k;
        int l = -1e18, r = 1e18;
        int res = -1e18;
        while(l <= r){
            int m = (l+r)/2;
            if(pos(m,k))res = m, l = m+1;
            else r = m-1;
        }
        cout << res << ' ';
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