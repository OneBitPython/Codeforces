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

int mod = 998244353;
int gcdExtended(int a, int b, int *x, int *y);

int ma(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int mm(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}
int ms(int a, int b){
    return ((((a%mod)-(b%mod))%mod)+mod)%mod;
}
int mxn = 3e5+1;
vector<int>fpf(mxn+1);
void pre(){
    for(int i = 2;i<=mxn;++i){
        if(fpf[i]==0){
            for(int j = i*i;j<=mxn;j+=i)fpf[j] = i;
        }
    }
}

vector<int>fact(int x){
    set<int>ret;
    while(x>1){
        if(fpf[x]==0)fpf[x] = x;
        ret.insert(fpf[x]);
        x/=fpf[x];
    }
    vector<int>c(all(ret));
    return c;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    pre();
    int res = 0;
    int bef = 1;
    int p = 1;
    for(int i = 1;i<=n;++i){
        bef = mm(bef,m);
        res = ma(res,bef);
    }
    int tot = 1;
    set<int>s;
    for(int i = 1;i<=n;++i){
        if(tot>m)continue;
        vector<int>f = fact(i);
        for(auto x : f){
            if(s.count(x)==0)tot*=x;
            s.insert(x);
        }
        p = mm(p, (m/tot)%mod);
        res = ms(res,p);
    }
    cout << res%mod << endl;
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