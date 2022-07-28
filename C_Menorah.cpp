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
    // number of changed values should be even or number of non changing values should be odd
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    vector<int>e, o;
    for(int i = 0;i<n;++i){
        if(a[i] != b[i])o.pb(a[i]-'0');
        else e.pb(a[i]-'0');
    }
    // even number of operations
    int res = 1e18;
    if(o.size()%2 == 0){
        int times = 0;
        int cnt1 = 0, cnt0 = 0;
        for(auto x : o){
            cnt1+=(x==1);
            cnt0+=(x==0);
        }
        if(cnt1 >= cnt0 && cnt1-cnt0 <= 1)res = min(res, (int)(o.size()));
    }
    // odd number of operations
    if(e.size()%2 == 1){
        int cnt1 = 0, cnt0 = 0;
        for(auto x : e){
            cnt1+=(x==1);
            cnt0+=(x==0);
        }
        if(cnt1 >= cnt0 && cnt1-cnt0<=1)res = min(res, (int)(e.size()));
    }

    if(res==1e18)cout << -1 << endl;
    else cout << res << endl;
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