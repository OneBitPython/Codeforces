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

int n,m;
int mini(const string &s){
    vector<int>dp(m+1);
    for(int i = 2;i<=m;++i){
        dp[i] = dp[i-1];
        if((s[i]-'0')&(s[i-1]-'0'))dp[i] = max(dp[i],dp[i-2]+1);
    }
    dbg(dp);
    int left = count(all(s),'1')-(min(m/4,dp[m])*2);
    return min(m/4,dp[m]) + left;
}

int maxi(const string &s){
    if(count(all(s),'1')==0)return 0ll;
    int sz = 0, cnt1  = 0;
    int res = 0;
    for(int i = 1;i<=m;++i){
        if(s[i]=='1')cnt1++;
        if(i>=2 && s[i]==s[i-1] && s[i]=='1'){
            res+=sz/2;
            sz = 1;
        }else sz++;
    }
    res+=sz/2;
    int c = max(0ll,(m/4)-res);
    return count(all(s),'1')-c;
}

void solve()
{
    cin >> n >> m;
    vector<string>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    int mn = 0,mx = 0;
    for(int i = 1;i<=n;++i){
        string s = a[i];
        s = "x"+a[i];
        mn += mini(s);
        mx+=maxi(s);
    }    
    cout<<mn << ' ' << mx << endl;
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