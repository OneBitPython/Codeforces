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
    int n,x;
    cin >> n >> x;
    vector<string>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<string>digits = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    vector<vector<int>>d(n+1, vector<int>(10));
    for(int i = 1;i<=n;++i){
        for(int j = 0;j<10;++j){
            // cost of setting a[i] to j
            int c = 0;
            bool ok = 1;
            for(int k = 0;k<7;++k){
                if(a[i][k] == '1' && digits[j][k] == '0'){
                    d[i][j] = -1;
                    ok = 0;
                    break;
                }
                if(a[i][k] == '0' && digits[j][k] == '1')c++;
            }
            if(ok)d[i][j] = c;
        }
    }
    vector<vector<int>>dp(n+2, vector<int>(x+1)); 
    dp[n+1][0] = 1;
    for(int i = n;i>=1;--i){
        for(int j = 0;j<=x;++j){
            for(int k = 0;k<10;++k){
                // set a[i] to k
                if(d[i][k] == -1)continue;
                if(j >= d[i][k] && dp[i+1][j-d[i][k]])dp[i][j] = 1;
            }
        }
    }
    if(!dp[1][x]){
        cout << - 1<< endl;
        return;
    }
    int start = 1;
    int val = x;
    string res;
    while(start <= n){
        bool ok = 0;
        for(int k = 9;k>=0;--k){
            // set a[start] to k
            if(d[start][k]==-1)continue;
            if(val >= d[start][k] && dp[start+1][val-d[start][k]]){
                res+=(k+'0');
                val-=d[start][k];
                start++;
                ok = 1;
                break;
            }
        }
        if(!ok){
            cout << -1;
            return;
        }
    }
    cout << res;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}