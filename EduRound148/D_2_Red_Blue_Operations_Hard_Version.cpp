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
vector<int>a,pref,mnn;
int summ(int a, int n){
    return (n*(2*a+(n-1)))/2;
}
bool pos(int x, int k){
    int l = lower_bound(all(a),x)-a.begin()-1, r = n;
    while(l <= r){
        int m = (l+r)/2;
        //k-i+1-x+a[i] for all i in prefix of length m >= (k-i)/2
        int sum = (k*m)+pref[m]-(x*m)-summ(0,m)+(pref[n]-pref[m]-(x*(n-m)));
        bool ok = 0;
        int left = k-m;
        if(left >= 0){
            if(left%2){
                if(m<n)sum+=left;
            }
            if(left%2){
                if(sum>=(left/2) && m < n)ok = 1;
            }else{
                if(sum>=(left/2))ok = 1;
            }
            
        }
        int mn = mnn[m]+k;
        if(ok && mn >= x){
            return 1;
        }else{
            if(left < 0)r =m-1;
            else l = m+1;
        }
    }
    return 0;
}
void solve()
{
    cin >> n >> q;  
    a.resize(n+1);
    mnn.resize(n+1);
    pref.resize(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];

    sort(a.begin()+1, a.end());
    for(int i = 1;i<=n;++i)pref[i] = pref[i-1]+a[i];
    a[0] = -1e18;
    mnn[0] = 1e18;
    for(int i = 1;i<=n;++i)mnn[i] = min(mnn[i-1],a[i]-i+1);
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