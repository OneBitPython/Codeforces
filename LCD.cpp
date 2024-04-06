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


int prime(int x){
    for(int i = 2;i<x;++i){
        if(x%i == 0)return 0;
    }
    return 1;
}
int dp[2][1ll<<17];
int mod = 1e9+7;


vector<int>pp(3e5);

int ma(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int mm(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}
int ms(int a, int b){
    return ((((a%mod)-(b%mod))%mod)+mod)%mod;
}
void pre(){
    pp[0] = 1;
    for(int i = 1;i<=2e5;++i)pp[i] = mm(pp[i-1],2);
}
void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int>a = {0};
    for(int i = 1;i<=n;++i){
        int x;cin >> x;
        if(x%k==0)a.pb(x);
    }
    n= a.size()-1;
    vector<int>p;
    for(int i = 2;i<=60;++i){
        if(prime(i))p.pb(i);
    }
    if(!prime(k)){
        cout << 0 << endl;
        return;
    }
    vector<pair<int,int>>b = {{0,0}};
    map<int,int>cnt;
    for(int i = 1;i<=n;++i){
        int cc = 0;
        for(int j = 0;j<17;++j){
            if((a[i]%(p[j]))==0)cc+=(1ll<<j);
        }
        cnt[cc]++;
    }
    
    for(auto x : cnt)b.pb({x.first,x.second});

    n = (int)(b.size())-1;
    unordered_set<int>pos = {b[1].first};

    unordered_set<int>nxt;
    dp[1][b[1].first] = b[1].second;
    for(int i = 2;i<=n;++i){
        nxt = pos;
        int curr = i%2;
        int prev = 1-curr;
        for(auto x : pos){
            int get = b[i].first&x;
            nxt.insert(get);
            dp[curr][get] = ma(dp[curr][get],mm(ms(pp[b[i].second],1) ,dp[prev][x]));
            dp[curr][x] = ma(dp[curr][x],dp[prev][x]);
            dp[prev][x] = 0;
        }
        pos = nxt;
        pos.insert(b[i].first);
        dp[curr][b[i].first] = ma(dp[curr][b[i].first],ms(pp[b[i].second],1));
    }
    int kk = 0;
    for(int i = 0;i<17;++i){
        if(p[i] == k)kk = i;
    }
    int cmp = (1ll<<kk)-1;
    int res =0;
    
    for(auto x : pos){
        if((x&cmp) == 0)res = ma(res,dp[n%2][x]);
        dp[n%2][x] = 0;
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
    pre();
    cin >> T;
    for(int i = 0;i<(1ll<<17);++i)dp[0][i] = 0,dp[1][i] = 0;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}