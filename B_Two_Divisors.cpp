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

int mxn = 1e7;
vector<int>pfp(mxn+1);
void pre(){
    for(int i = 2;i<=mxn;++i){
        if(pfp[i]==0){
            pfp[i] = i;
            for(int j = i*i;j<=mxn;j+=i)pfp[j] = i;
        }
    }
}
vector<int> fact(int x){
    int res = 0;
    vector<int>dist;
    while(x!=1){
        dist.pb(pfp[x]);
        x/=pfp[x];
    }
    sort(all(dist));
    dist.erase(unique(all(dist)),dist.end());
    return dist;
}
int multi(vector<int>&d){
    int res = 1;
    for(auto x : d)res*=x;
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>r1,r2;
    for(int i = 1;i<=n;++i){
        int x;
        cin >> x;
        vector<int>d = fact(x);
        int m = d.size();
        bool ok = 0;
        int mul = multi(d);
        for(int j = 1;j<(1ll<<m);++j){
            int prod = 1;
            for(int k = 0;k<m;++k){
                if(j&(1ll<<k))prod*=d[k];
            }
            int lef = mul/prod;
            if(lef!=1 && prod!=1){
                if(__gcd(x,lef+prod)==1){
                    ok = 1;
                    r1.pb(lef);
                    r2.pb(prod);
                    break;
                }
            }
        }   
        if(!ok){
            r1.pb(-1);
            r2.pb(-1);
        }
    }
    for(auto x : r1) cout << x << ' ';
    cout << endl;
    for(auto x : r2) cout << x << ' ';
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
    pre();
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}