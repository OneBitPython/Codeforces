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


int n;
vector<int>a;
void out(int start){
    vector<int>res(n+1);
    res[1] = start;
    for(int j = 2;j<=n;++j)res[j] = res[j-1]^a[j-1];
    for(int i = 1;i<=n;++i)cout << res[i] << ' ';
    cout << endl;
}
void solve()
{

    cin >> n;
    a.resize(n+1);
    for(int i = 1;i<n;++i)cin >> a[i];

    set<int>b;
    int c= 0;
    for(int j = 1;j<n;++j){
        c^=a[j];
        b.insert(c);
    }
    int u = n-1;
    bool got = 0;
    int start = 0;
    for(int j = 30;j>=0;--j){
        if(b.size()==0)break;
        if(u&(1ll<<j)){
            set<int>g1, g0;
            for(auto x : b){
                if((x&(1ll<<j)))g1.insert(x);
                else g0.insert(x);
            }
            if(g0.size() >= g1.size()){
                for(auto x : g0)b.erase(x);
            }else{
                start+=(1ll<<j);
                for(auto x : g1)b.erase(x);
            }
            got = 1;
        }else{
            if(!got)continue;
            start+=((*b.begin())&(1ll<<j));
        }
    }
    out(start);
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