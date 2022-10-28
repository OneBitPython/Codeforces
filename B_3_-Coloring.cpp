#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
// #define endl "\n"

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


void query(int a, int b, int c){
    cout << a << ' ' << b << ' ' << c << endl;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>a(n+1, vector<int>(n+1));
    int m = n*n;
    int i = 1, j = 1;
    while(m--){
        int c;
        cin >> c;
        vector<int>neighbours;
        if(i > 1)neighbours.pb(a[i-1][j]);
        if(j > 1)neighbours.pb(a[i][j-1]);
        set<int>choice = {1,2,3};
        for(auto x : neighbours)choice.erase(x);
        choice.erase(c);
        query(*choice.begin(),i,j);
        a[i][j] = *choice.begin();
        j++;
        if(j > n){
            i++;
            j = 1;
        }
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
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