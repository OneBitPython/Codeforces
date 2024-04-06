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


int give(vector<int>&a){
    int n = (int)(a.size())-1;
    vector<int>dp(n+1);
    for(int i = 1;i<=n;++i){
        dp[i] = 1;
        for(int j = i-1;j>=1;--j){
            if(a[j] < a[i])dp[i] = max(dp[i], dp[j]+1);
        }
    }
    return *max_element(dp.begin()+1, dp.end());
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<int>b(m+1);
    for(int i = 1;i<=m;++i)cin >> b[i];
    vector<int>res(n+m+1);
    sort(b.begin()+1, b.end(),greater<int>());
    int ptr1 = 1, ptr2 = 1;
    for(int i = 1;i<=(n+m);++i){
        if(ptr2 > m){
            res[i] = a[ptr1];
            ptr1++;
        }else{            
            if(ptr1 <= n && a[ptr1] >= b[ptr2])res[i] = a[ptr1++];
            else res[i] = b[ptr2++];
        }
        cout << res[i] << ' ';
    }
    // assert(give(res)==give(a));
    cout << endl;
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