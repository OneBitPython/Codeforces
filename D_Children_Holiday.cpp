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

struct node{
    int t = 0, y =0, z = 0;
    int time(int x){
        // time to blow x baloons
        int c = (x/z);
        if(x%z == 0)c--;
        return (t*x)+(c*y);
    }
};
vector<node>a;
int m,n;
vector<int>ans;
bool pos(int x){
    // check if you can blow m baloons in x seconds
    vector<int>b(n+1);
    int sum = 0;
    int rem = m;
    for(int i = 1;i<=n;++i){
        // binary search on the number of balloons you can blow in x seconds
        int l = 0, r= 1e12;
        int curr = 0;
        while(l <= r){
            int w = (l+r)/2;
            if(a[i].time(w)<=x)curr = w, l = w+1;
            else r = w-1;
        }
        int add = min(curr,rem);
        b[i] = add;
        sum+=add;
        rem-=add;
    }
    if(sum==m){
        ans = b;
        return 1;
    }
    return 0;
}
void solve()
{
    cin >> m >> n;
    a.resize(n+1);
    int df = 1e12;
    for(int i = 1;i<=n;++i)cin >> a[i].t >> a[i].z >> a[i].y;
    int l = 0,r=1e12;
    while(l <= r){
        int q = (l+r)/2;
        if(pos(q))df = q, r = q-1;
        else l = q+1;
    }
    cout << df << endl;
    for(int i = 1;i<=n;++i)cout << ans[i] << ' ';
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}