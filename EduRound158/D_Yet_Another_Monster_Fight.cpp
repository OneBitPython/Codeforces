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


vector<int>a;
int n;
bool pos(int x){
    int cnt = 0;
    // if a guy has a problemwith his left and right, then he has to be chosen
    // find leftmost person with a problem in his right and rightmost person with a problem in the left
    // if they have soem intersection then it's all good
    int cc = 0;
    for(int i = 1;i<=n;++i){
        int val = x-a[i];
        if(val < 0)return 0;
        if((n-i) > val && ((i-1) > val))cnt++,cc=i;
    }
    if(cnt > 1)return 0;
    int leftmost = n,rightmost = 0;
    for(int i = 1;i<=n;++i){
        int val = x-a[i];
        if((n-i) > val){
            leftmost = i;
            break;
        }        
    }
    for(int i = n;i>=1;--i){
        int val = x-a[i];
        if((i-1) > val){
            rightmost = i;
            break;
        }        
    }
    if(leftmost < rightmost)return 0;
    if(cc!=0){
        if(cc <= leftmost && cc >= rightmost)return 1;
    }
    return 1;
}
void solve()
{
    cin >> n;
    a.resize(n+1);
    for(int i =1 ;i<=n;++i)cin >> a[i];
    int l = 0ll, r = 1e16;
    int res = 1e18;
    while(l <= r){
        int m = (l+r)/2;
        if(pos(m))res = min(res, m), r = m-1;
        else l = m+1;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}