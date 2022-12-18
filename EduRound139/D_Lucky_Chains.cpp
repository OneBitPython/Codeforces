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

int N = 1e7;
vector<int>fpf(N+1);
void pre(){
    for(int i = 2;i<=N;++i){
        if(fpf[i]==0){
            for(int j = i*i;j<=N;j+=i)fpf[j] = i;
        }
    }
}

int fact(int x, int w){
    int res = 1e18;
    int y = x;
    while(x!=1){
        if(fpf[x] == 0)fpf[x] = x;
        int val = (w/fpf[x])+(w%fpf[x]==0?0:1);
        int first = fpf[x]*val;
        res = min(res, first-w);
        x/=fpf[x];
    }
    return res;
}

void solve()
{
    int x,y;
    cin >> x >> y;
    if(x > y)swap(x,y);
    if(__gcd(x,y)>1){
        cout << 0 << endl;
        return;
    }
    int diff = y-x;
    if(diff==1){
        cout << -1 << endl;
        return;
    }
    int f = fact(diff,x);
    cout <<f  << endl;
    
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
    pre();

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}