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
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    if(a[1]==n){
        int pos = 0;
        for(int i = 1;i<=n;++i){
            if(a[i]==(n-1))pos = i;
        }
        if(pos==0){
            cout << 1 << endl;
            return;
        }

        if(pos==n){
            cout << a[pos] << ' ';
            for(int i = 1;i<pos;++i)cout << a[i] << ' ';
            cout << endl;
            return;
        }
        for(int i = pos;i<=n;++i)cout << a[i] << ' ';
        if(n>1)cout << a[pos-1] << ' ';
        for(int i = 1;i<pos-1;++i)cout << a[i] << ' ';
        cout << endl;
        return;
    }
    vector<vector<int>>pos;
    int p = 1;
    for(int i = 1;i<=n;++i){
        if(a[i]==n)p = i;
    }
    vector<int>rev;
    for(int i = p-1;i>=1;--i){
        rev.pb(a[i]);
        vector<int>get;
        for(int i = p;i<=n;++i)get.pb(a[i]);
        for(auto x : rev)get.pb(x);
        for(int j = 1;j<i;++j)get.pb(a[j]);
        pos.pb(get);
    }
    vector<int>get;
    for(int i = p+1;i<=n;++i)get.pb(a[i]);
    get.pb(n);
    for(int i = 1;i<p;++i)get.pb(a[i]);
    pos.pb(get);
    sort(all(pos));
    for(auto x : pos.back())cout << x << ' ';
    cout << endl;
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