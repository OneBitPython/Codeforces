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
    cin>> n;
    int tot = 0;
    vector<vector<int>>a(n, vector<int>(n));
    for(int i = 0;i<n;++i){
        string s;
        cin >> s;
        for(int j = 0;j<n;++j){
            a[i][j] = (s[j]-'0');
            tot+=(a[i][j] == 1);
        }
    }
    int res = 1e18;
    for(int i = 0;i<n;++i){
        // i+1 cyclic shifts left
        int r = n-1-i;
        int c = 0;
        int cnt0 = 0;
        for(int j = 0;j<=i;++j){
            if(r < n && c < n)cnt0+=(a[r][c] == 0);
            r++;
            c++;
        }
        r = 0;
        for(int j = 0;j<n-i-1;++j){
            if(r < n && c < n)cnt0+=(a[r][c] == 0);
            r++;
            c++;
        }
        int cnt1 = n-cnt0;
        res = min(res, (tot-cnt1)+cnt0);
    }
    cout << res << endl;
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