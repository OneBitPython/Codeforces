#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    if(n%2){
        int res = 0;
        for(int i = 1;i<n;i+=2){
            if(i >= n-1)break;
            int val = max(a[i-1], a[i+1])+1;
            if(a[i] < val){
                res+=(val-a[i]);
            }
        }
        cout << res << endl;
    }else{
        int c1 = 0;
        for(int i = 2;i<n;i+=2){
            if(i>=n-1)break;
            int val = max(a[i-1], a[i+1])+1;
            if(a[i] < val){
                c1+=(val-a[i]);
            }
        }
        vector<int>dp(n);
        int c2 = 0;
        for(int i = n-2;i>=0;i-=2){
            if(i < 1)break;
            int val = max(a[i-1], a[i+1])+1;
            if(a[i] < val){
                c2+=(val-a[i]);
            }
            dp[i] = c2;
        }
        int c3 = 1e18;
        int cost = 0;
        for(int i = 1;i<n;i+=2){
            if(i >= n-1)break;
            int val = max(a[i-1], a[i+1])+1;
            if(a[i] < val){
                cost+=(val-a[i]);
            }
            int tot = cost;
            if(i+3 < n)tot+=dp[i+3];
            c3 = min(c3, tot);
        }
        int c4 = 0;
        for(int i = 1;i<n;i+=2){
            if(i >= n)break;
            int val = max(a[i-1], a[i+1])+1;
            if(a[i] < val){
                c4+=(val-a[i]);
            }
        }
        cout << min({c1, c3, c4}) << endl;
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}