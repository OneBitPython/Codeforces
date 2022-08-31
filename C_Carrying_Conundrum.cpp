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

int fc(int x){
    int cnt = 0;
    set<int>st;
    for(int i = 0;i<=9;++i){
        for(int j = 0;j<=9;++j){
            // if(i == 0 && j == 0)continue;
            if(i+j == x)st.insert({i,j });
        }
    }
    return st.size();
}

int cost(string &b){
    int m = b.size();
    if(m == 0)return 1;
    vector<vector<int>>dp(m, vector<int>(2));
    dp[0][0] = fc(b[0]-'0');
    if(m > 1)dp[0][1] = fc(b[0]-'0' + 10);
    for(int i = 1;i<m;++i){
        int c = fc(b[i]-'0');
        dp[i][0] = c * (dp[i-1][0]);
        int val = b[i]-'0' - 1;
        dp[i][0] += fc(val) * dp[i-1][1];
        if(i == m-1)break;
        c = b[i]-'0' + 10;
        dp[i][1] = fc(c) * dp[i-1][0];
        dp[i][1] += dp[i-1][1] * fc(c-1);
    }
    
    return dp[m-1][0];
}

void solve()
{
    string s;
    cin >> s;
    string a,b;
    int n = s.size();
    for(int i = n-1;i>=0;i-=2){
        a+=s[i];
    }
    for(int i = n-2;i>=0;i-=2)b+=s[i];
    cout << cost(a) * cost(b) - 2 << endl;
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