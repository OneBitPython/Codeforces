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
    int n,m;
    cin >> n >> m;
    vector<int>one,two;
    vector<int>a(n);
    for(int i = 0;i<n;++i){
        cin >> a[i];
    }
    for(int i = 0;i<n;++i){
        int c;
        cin >> c;
        if(c==2)two.pb(a[i]);
        else one.pb(a[i]);
    }
    sort(all(one),greater<int>());
    sort(all(two),greater<int>());
    int res = 1e18;
    vector<int>p;
    if(!one.empty())p.pb(one[0]);
    for(int i = 1;i<(int)(one.size());++i){
        p.pb(p.back()+one[i]);
    }
    int sum = 0;
    for(int i = 0;i<(int)(two.size());++i){
        sum+=two[i];
        if(sum>=m){
            res = min(res, 2*(i+1));
            break;
        }
    }
    for(int i = 0;i<(int)(one.size());++i){
        if(p[i] >= m){
            res = min(res, i+1);
            break;
        }
    }
    sum = 0;
    for(int i = 0;i<(int)(two.size());++i){
        sum+=two[i];
        int req = m-sum;
        if(req <= 0)break;
        int pos = lower_bound(all(p),req)-p.begin();
        if(pos==(int)(p.size()))continue;
        res = min(res, (i+1)*2 + 1 +pos);
    }
    if(res>=1e18)res = -1;
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
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}