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

string f(int n){
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    
    return s;
}
vector<vector<int>>dp(20,vector<int>(10));
void pre(){
    for(int i = 0;i<=9;++i){
        dp[1][i]=(i>=4);
    }
    for(int i = 2;i<=19;++i){
        dp[i][0] = dp[i-1][9];
        for(int j = 1;j<=9;++j){
            dp[i][j]=dp[i][j-1]+dp[i-1][9];
            if(j==4)dp[i][j]+=(pow(10,i-1)),dp[i][j]-=dp[i-1][9];
        }
    }
}
int give(int n){
    // find number of bad integers <= n
    int res = 0;
    string s = f(n);
    int sz = s.size();
    int e = 0;
    for(int i = 0;i<(int)(s.size())-1;++i){
        if(s[i]-'0' != 0)res+=dp[sz-i][(s[i]-'0')-1];

        if((s[i]-'0')==4){
            for(int j =sz-1;j>i;--j)res+=(s[j]-'0')*(pow(10,sz-j-1));
            res++;
            e = 1;
            break;
        }
    }
    if(!e)res+=dp[1][s.back()-'0'];

    return res;
}

void solve()
{
    int n;
    cin >> n;
    
    int l = n,r=1e18;
    int res = 1e18;
    while(l <= r){
        int m = (l+r)/2;
        int x = m-give(m);
        if(x==n){
            res  = m;
            r = m-1;
        }else if(x < n)l = m+1;
        else r = m-1;
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
    pre();
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}