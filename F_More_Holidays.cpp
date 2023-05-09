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

int n,k,M;
string s;
vector<int>pref,suff;

int get(int i, int x){
    if(x<0)return 0;
    int left = k-(suff[i]+(x*suff[1]));
    int pos = upper_bound(all(pref),left)-pref.begin()-1;

    return (n-i+1)+(x*n)+(pos);
}
int pos(int i, int x, int &res){
    // take suffix startin from and x copies of s
    if(suff[i]+(x*suff[1]) > k)return 0;
    res = max({res, get(i,x)});
    return 1;
}
void solve()
{
    cin >> n >> M >> k;
    cin >> s;
    // you consider taking some prefix of s + (some copies of s) + some suffix of s      
    s = "0"+s;
    pref.resize(n+1);
    suff.resize(n+2);
    for(int i= 1;i<=n;++i){
        pref[i] = pref[i-1]+(s[i]=='x');
    }
    //oxxoxoxxoxoxxox
    for(int i = n;i>=1;--i)suff[i] = suff[i+1]+(s[i]=='x');
    int ans = 0;
    for(int i = 1;i<=n;++i){
        int pos = lower_bound(all(pref),k+pref[i-1]+1)-pref.begin();
        ans = max(ans, pos-i);
    }
    if(M==1){
        cout << ans << endl;
        return;
    }
    for(int i = 1;i<=n;++i){
        int l = 0, r = M-2;
        int res = 0;
        while(l <= r){
            int m = (l+r)/2; // consider taking m copies of s
            if(pos(i,m,res)){
                l = m+1;
            }else r= m-1;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
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