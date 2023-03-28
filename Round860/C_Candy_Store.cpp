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


int l(int a, int b){
    return (a*b)/__gcd(a,b);
}
int mxn = 4e4;
vector<int>prime(mxn+1,1);
vector<int>p;

void pre(){
    prime[0] = prime[1] = 0;
    for(int i = 2;i*i<=mxn;++i){
        if(prime[i]){
            for(int j = i*i;j<=mxn;j+=i)prime[j] = 0;
        }
    }
    for(int i = 1;i<=mxn;++i){
        if(prime[i])p.pb(i);
    }
}
vector<int>give(int y){
    vector<int>c(mxn+1);
    for(auto x : p){
        while(y%x == 0){
            y/=x;
            c[x]++;
        }
    }
    if(y > 0)c[y]++;
    return c;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1),b(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i] >> b[i];
    int res = 1;
    vector<int>mn(mxn+1,1e18);
    int lcm = b[1];
    dbg(p.size());
    for(int i = 1;i<=n;++i){
        // prime factorize each b[i]
        int bef = lcm;
        lcm = l(lcm,b[i]);
        int d = lcm/b[i];

        int diff = lcm/bef;
        vector<int>c = give(diff);
        bool ok = 1;
        for(auto x : p){    
            if(mn[x]==1e18 && c[x])ok = 0;
            mn[x]-=c[x];
            if(mn[x] < 0){
                ok = 0;
            }
        }
        if(((a[i]%d)==0) && ok){

        }else{
            res++;
            for(auto x : p)mn[x] = 1e18;
            lcm = b[i];
        }
        c = give(a[i]);
        d = lcm/b[i];
        for(auto x : p){
            int w = 0;
            while((d%x) == 0){
                d/=x;
                w++;
            }
            mn[x] = min(mn[x], c[x]-w);
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
    // freopen("error.txt", "w", stderr);
    // #endif

    int T=1;
    cin >> T;
    pre();
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}