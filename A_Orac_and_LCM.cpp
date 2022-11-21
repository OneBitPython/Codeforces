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


set<int>dist;
vector<multiset<int>>c(2e5+6);

void fact(vector<int>&fpf, int x){
    map<int,int>mp;
    while(x != 1){
        mp[fpf[x]]++;
        dist.insert(fpf[x]);
        x/=fpf[x];
    }
    for(auto x : mp){
        c[x.first].insert(x.second);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    int mxn = 2e5+5;
    vector<int>fpf(mxn+1);
    for(int i = 2;i*i<=mxn;++i){
        if(fpf[i] == 0){
            for(int j = i*i;j<=mxn;j+=i)fpf[j] = i;
        }
    }
    for(int i = 1;i<=mxn;++i){
        if(fpf[i]==0)fpf[i] = i;
    }
    // all distinct prime factors
    for(int i = n-1;i>=0;--i){
        fact(fpf,a[i]);
    }
    int res = 1;
    for(auto x : dist){
        if(c[x].size() < n){
            int t = 0;
            while(t < 2 && c[x].size() < n)c[x].insert(0),t++;
        }
        c[x].erase(c[x].begin());
        res*=(pow(x,*c[x].begin()));
    }
    cout << res;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}