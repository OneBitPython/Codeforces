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


vector<int>d;
void f(int l, int r, int v){
    // from l to r inclusive
    if(r < l)return;
    d[l]+=v;
    d[r+1]-=v;
}

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    d.resize(n+5);
    for(int i = 1;i<=n;++i)cin >> a[i];

    for(int i = 1;i<=n;++i){
        if(i< a[i]){
            f(1,a[i]-i,-1);
            f(a[i]-i+1, n-i,1);
            int x = a[i]-1 - abs(a[i]-n);
            f(n-i+1, n-i+1,x);
            f(n-i+2,n-1,-1);
        }else{
            f(1,n-i,1);
            int x = a[i]-1-abs(a[i]-n);
            f(n-i+1,n-i+1,x);
            f(n-i+2,n-i+2+(a[i]-2),-1);
            f(n-i+2+a[i]-2+1, n-1,1);
        }
    }
    vector<int>b(n);
    b[0] = d[0];
    for(int i = 1;i<n;++i){
        b[i] = b[i-1]+d[i];
    }

    vector<int>res;
    int dev = 0;
    for(int i = 1;i<=n;++i)dev+=abs(a[i]-i);
    vector<int>c(n);
    c[0] = dev;
    for(int i =1;i<n;++i)c[i] = c[i-1]+b[i];

    int best = dev;
    int y = 0;
    for(int i = 0;i<n;++i){
        if(c[i] < best){
            best = c[i];
            y = i;
        }
    }

    cout << best << ' ' << y << endl;
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