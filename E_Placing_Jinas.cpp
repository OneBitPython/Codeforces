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

int f(int x, int a, int b, int c, int d){
    return (2*pow(x,5)) + (a*pow(x,4))+(b*pow(x,3))+(c*pow(x,2))+(d*x)+4;
}

void solve()
{   
    map<int,int>sol = {
        {0,4},
        {1,5},
        {2,8},
        {3,13},
        {4,20}
    };
    cout << "ok" << endl;
    int bound = 100;
    for(int a = -bound;a<=bound;++a){
        for(int b = -bound;b<=bound;++b){
            for(int c = -bound;c<=bound;++c){
                for(int d = -bound;d<=bound;++d){
                    dbg(a,b,c,d);
                    bool ok = 1;
                    for(auto x : sol)ok&=(f(x.first,a,b,c,d)==x.second);
                    if(ok){
                        dbg(a,b,c,d);
                        dbg(f(4,a,b,c,d));
                        return;
                    }
                }
            }
        }
    }
    dbg(f(5,-34,168,-295,160));
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}