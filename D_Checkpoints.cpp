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


const int N = 201;
int n,l;
int dp[N][N][N][2]; // dp[i][j][k][l] min time required to reach k checpoints out of prefix i and suffix j 
int dist(int x, int y){
    if(x > y)swap(x,y);
    return min(abs(x-y),x+l-y);
}
void solve()
{
    cin >> n >> l;
    vector<int>a(n+2),t(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=n;++i)cin >> t[i];
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=n;++j){
            for(int k = 0;k<=n;++k){
                dp[i][j][k][0] = dp[i][j][k][1] = 1e18;
            }
        }
    }
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    int res = 0;
    for(int i= 0;i<=n;++i){
        for(int j = 0;j<=n;++j){
            if(i==j && i == 0)continue;
            int tot = i+j;
            int l = i, r = n-j+1;
            if(r <= l)continue;
            for(int k = 0;k<=tot;++k){
                if(i > 0 && k!=tot){
                    int c = 1e18;
                    if(i==1){
                        if(j>0){
                            c = dp[i-1][j][k][1]+dist(a[l],a[r]);
                        }else{
                            c = dist(a[l],0);
                        }
                    }else{
                        c = min(dp[i-1][j][k][0]+dist(a[l],a[l-1]),dp[i-1][j][k][1]+dist(a[l],a[r]));
                    }
                    dp[i][j][k][0] = min(dp[i][j][k][0],c);
                }
                if(j > 0 && k!=tot){
                    int c = 1e18;
                    if(j==1){
                        if(i>0){
                            c = dp[i][j-1][k][0]+dist(a[r],a[l]);
                        }else c = dist(a[r],0);
                    }else{
                        c = min(dp[i][j-1][k][0]+dist(a[r],a[l]),dp[i][j-1][k][1]+dist(a[r],a[r+1]));
                    }
                    dp[i][j][k][1] = min(dp[i][j][k][1],c);
                }
                if(dp[i][j][k][0]<(1e18) || dp[i][j][k][1]<1e18){
                    res = max(res, k);
                }
                if(!k)continue;
                if(i > 0){
                    int c = 1e18;
                    if(i==1){
                        if(j>0){
                            c = dp[i-1][j][k-1][1]+dist(a[l],a[r]);
                        }else{
                            c = dist(a[l],0);
                        }
                    }else{
                        c = min(dp[i-1][j][k-1][0]+dist(a[l-1],a[l]), dp[i-1][j][k-1][1]+dist(a[l],a[r]));
                    }
                    if(c <= t[l])dp[i][j][k][0] = min(dp[i][j][k][0],c);
                }
                if(j > 0){
                    int c = 1e18;
                    if(j==1){
                        if(i>0){
                            c = dp[i][j-1][k-1][0]+dist(a[l],a[r]);
                        }else c = dist(a[r],0);
                    }else{
                        c = min(dp[i][j-1][k-1][0]+dist(a[l],a[r]),dp[i][j-1][k-1][1]+dist(a[r],a[r+1]));
                    }
                    if(c <= t[r])dp[i][j][k][1] = min(dp[i][j][k][1],c);
                }
                if(dp[i][j][k][0]<(1e18) || dp[i][j][k][1]<1e18){
                    res = max(res, k);
                }
            }

        }
    }
    cout<<res;
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