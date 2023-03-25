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


bool same(vector<int>&a, vector<int>&b){
    return a==b;
}
bool inv(vector<int>&a, vector<int>&b){
    for(int i = 1;i<(int)(a.size());++i){
        if(a[i]==b[i])return 0;
    }
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>a(n+1, vector<int>(n+1));
    for(int i = 1;i<=n;++i){
        string s;
        cin >> s;
        for(int j= 1;j<=n;++j)a[i][j] = s[j-1]-'0';
    }
    for(int i = 1;i<=n;++i){
        string s;
        cin >> s;
        for(int j= 1;j<=n;++j)a[i][j]^=(s[j-1]-'0');
    }
    for(int i = 2;i<=n;++i){
        if(same(a[1],a[i]) || inv(a[1],a[i])){

        }else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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