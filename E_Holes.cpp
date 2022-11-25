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


const int mxn = 1e5+5;
int dp[mxn+1][2];
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    int sz = sqrt(n);
    int g = (n-1)/sz;
    for(int i = n-1;i>=0;--i){
        if(i+a[i]>=n){
            dp[i][0] = 1;
            dp[i][1] = -1;
        }else{
            int g1 = i/sz, g2 = (i+a[i])/sz;
            if(g1==g2){
                dp[i][0] = dp[i+a[i]][0]+1;
                dp[i][1] = dp[i+a[i]][1];
                if(dp[i+a[i]][1] == -1){
                    dp[i][0] = 1;
                    dp[i][1] = i+a[i];
                }
            }else dp[i][0] = 1, dp[i][1] = i+a[i];
        }
    }
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int x;
            cin >> x;
            x--;
            // start from hole x
            int res = 0;
            int node = -1;
            while(x!=-1){
                res+=dp[x][0];
                if(dp[x][1] == -1)node = x;
                x = dp[x][1];
            }
            cout << node+1 << ' ' << res <<  endl;
        }else{
            int x,b;
            cin >> x >> b;
            x--;
            a[x] = b;
            int g1 = x/sz;
            for(int j = x;j>=g1*sz;--j){
                if(j+a[j] >= n){
                    dp[j][0] = 1;
                    dp[j][1] = -1;
                }else{
                    int g1 = j/sz, g2 = (j+a[j])/sz;
                    if(g1==g2){
                        dp[j][0] = dp[j+a[j]][0]+1;
                        dp[j][1] = dp[j+a[j]][1];
                        if(dp[j+a[j]][1] == -1){
                            dp[j][0] = 1;
                            dp[j][1] = j+a[j];
                        }
                    }else dp[j][0] = 1, dp[j][1] = j+a[j];
                }
            }
        }   
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
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}

