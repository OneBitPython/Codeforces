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



void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int>a(n+1),b(m+1);
    for(int i= 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=m;++i)cin >> b[i];
    int res = a[1];
    for(int i = 2;i<=n;++i)res^=a[i];
    vector<int>get(35);
    for(int j =1;j<=m;++j){
        for(int k = 0;k<=34;++k){
            if(b[j]&(1ll<<k))get[k] = 1;
        }
    }
    int val = 0;
    for(int j = 0;j<=30;++j){
        if(get[j])val+=(1ll<<j);
    }
    for(int i =1;i<=n;++i)a[i]|=val;
    if(n%2){
        int high = 0;

        high = a[1];
        for(int  j= 2;j<=n;++j)high^=a[j];
        cout << res << ' ' << high << endl;
    }else{
        int low = 0;
        low = a[1];
        for(int  j= 2;j<=n;++j)low^=a[j];
        cout << low << ' ' << res << endl;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}