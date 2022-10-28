#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

// const long double PI=3.141592653589;


// void __print(int x) {cerr << x;}
// void __print(long x) {cerr << x;}
// void __print(unsigned x) {cerr << x;}
// void __print(unsigned long x) {cerr << x;}
// void __print(unsigned long long x) {cerr << x;}
// void __print(float x) {cerr << x;}
// void __print(long double x) {cerr << x;}
// void __print(long long double x) {cerr << x;}
// void __print(char x) {cerr << '\'' << x << '\'';}
// void __print(const char *x) {cerr << '\"' << x << '\"';}
// void __print(const string &x) {cerr << '\"' << x << '\"';}
// void __print(bool x) {cerr << (x ? "true" : "false");}

// template<typename T, typename V>
// void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
// template<typename T>
// void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
// void _print() {cerr << "]\n";}
// template <typename T, typename... V>
// void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
// #ifndef ONLINE_JUDGE
// #define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
// #else
// #define dbg(x...)
// #endif



void solve()
{
    int n;
    cin >> n;
    vector<long double>a(n);
    for(int i = 0;i<n;++i)cin >> a[i];
    sort(all(a),greater<long double>());
    long double res = a[0];
    for(auto x : a)cout<< x << ' ';
    cout << endl;
    for(int i = 1;i<n;++i){
        long double ans = 0.0;
        for(int j = 0;j<=i;++j){
            // multiply other values and then multiply with 1-a[j]
            long double c =(1.0-a[j]);
            for(int k = 0;k<=i;++k){
                if(k == j)continue;
                c*=(a[k]*1.0);
            }
            cout << c << endl;
            ans+=c;
        }
        res = max(res, ans);
    }
    cout << fixed << setprecision(15) << res << endl;
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