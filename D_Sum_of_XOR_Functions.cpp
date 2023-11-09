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

// i = 9 is an issue, should be 34
/*
00101000101010001110000

cnt1 = 7
g1 = 28

i = 9
cnt1 = 7
g1 = 31
cnt2 = 2
g2 = 11
curr = 0

001 0001

0101
*/
int mod = 998244353;
int ma(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int mm(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    int res = 0;
    for(int j = 0;j<=30;++j){
        int prev = 0,g1=0,g2=0,cnt1 = 0, cnt2 =0;
        bool curr = 1;
        for(int i = 1;i<=n;++i){
            if(curr){
                cnt1++;
            }else{
                cnt2++;
            }
            g1+=cnt1;
            g2+=cnt2;
            if((a[i]&(1ll<<j))){
                prev = i;
                curr = !curr;
            }
            if(prev==0)continue;
            if(curr){
                res = ma(res, mm((1ll<<j),g2));
            }else{
                res = ma(res, mm((1ll<<j),g1));
            }
        }
    }
    cout << res%(mod) << endl;
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