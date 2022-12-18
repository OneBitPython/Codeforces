#include <bits/stdc++.h>
using namespace std;

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


const int N = 2e5;

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int>cards(2e5),f(2e5);
    for(int i = 1;i<=n*k;++i){
        int v;
        cin >> v;
        cards[v]++;
    }
    for(int i = 1;i<=n;++i){
        int v;
        cin >> v;
        f[v]++;
    }
    vector<int>h(k+1);
    for(int i = 1;i<=k;++i)cin >> h[i];
    // player getrs h[t] happiness if they get t of their favourite card    
    // h is in incrasing order
    // if all players have different favourites, then you greedily give max possible number of favourite cards to each player
    int res = 0;
    for(int i = 1;i<=1e5;++i){
        if(cards[i] == 0 || f[i] == 0)continue;
        vector<vector<vector<int>>>dp(cards[i]+1, vector<vector<int>>(f[i]+1, vector<int>(k+1)));
        for(int j = 1;j<=cards[i];++j){
            for(int l = 1;l<=f[i];++l){
                for(int m = 0;m<=k;++m){
                    // dp[j][l][m] max cost if you split j cards among l groups and lth group gets m cards
                    if(m > j)break;
                    for(int o = 0;o<=k;++o){
                        if(o > (j-m))break;
                        dp[j][l][m] = max(dp[j][l][m], dp[j-m][l-1][o]+ h[m]);
                    }
                }
            }
        }
        int ans = 0;
        for(int j = 0;j<=k;++j)ans = max(ans, dp[cards[i]][f[i]][j]);
        res += ans;
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
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}