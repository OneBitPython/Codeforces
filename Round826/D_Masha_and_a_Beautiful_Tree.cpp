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
    int m;
    cin>> m;
    vector<int>a(m);
    for(int &u : a)cin >> u;
    int res = 0;
    for(int i = 1;i<=30;++i){
        int n = (1ll<<i);
        if((n) > m)break;
        for(int j = 0;j<m;){
            // take two groups, both of size 2^i-1
            int mn_first = 1e18;
            int sz = n/2;
            for(int k = j;k<(j+sz);++k){
                mn_first = min(mn_first, a[k]);
            }
            int max_second = 0;
            for(int k = j+sz;k<j+n;++k)max_second = max(max_second, a[k]);

            if(mn_first > max_second){
                // swap
                res++;
                for(int k = j;k<j+sz;++k)swap(a[k],a[k+sz]);
            }
            j+=n;
        }
    }
    for(int i =1;i<=m;++i){
        if(a[i-1]!=i){
            cout << -1 << endl;
            return;
        }
    }
    cout << res << endl;
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