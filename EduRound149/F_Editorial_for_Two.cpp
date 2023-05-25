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
int n,k;
bool pos(int x){

    vector<int>dp(n+2);
    priority_queue<int>pq;
    int sum = 0,took = 0;
    for(int i = n;i>=1;--i){
        pq.push(a[i]);
        sum+=a[i];
        took++;
        while(!pq.empty() && sum > x){
            sum-=pq.top();
            pq.pop();
            took--;
        }
        
        dp[i] = took;
    }
    while(!pq.empty())pq.pop();
    sum = took = 0;
    for(int i = 1;i<=n;++i){
        sum+=a[i];
        pq.push(a[i]);
        took++;
        while(!pq.empty() && sum > x){
            sum-=pq.top();
            pq.pop();
            took--;
        }
        if(took+dp[i+1] >= k)return 1;
    }
    return 0;
}
void solve()
{
    cin >> n >> k;
    a = vector<int>(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    int l = 0, r = 1e15;
    int res = 1e15;
    while(l <= r){
        int m = (l+r)/2;
        if(pos(m))res = m,r = m-1;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}