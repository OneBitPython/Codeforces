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
    int n,x;
    cin >> n >> x;
    int res =0;
    bool change = 0;
    int mx = -1;
    for(int i = 0;i<=60;++i){
        if(x&(1ll<<i)){
            if((n&(1ll<<i)) == 0){
                cout << -1 << endl;
                return;
            }
        }
        if((n&(1ll<<i))&&(x&(1ll<<i)))change = 1;
        if((n&(1ll<<i))){
            if((x&(1ll<<i))==0){
                if(change){
                    cout << -1 << endl;
                    return;
                }else{
                    mx = max(mx, i);
                }
            }   
        }
    }
    if(mx==-1){
        cout << n << endl;
        return;
    }
    mx++;
    if(n&(1ll<<mx)){
        cout << -1 << endl;
        return;
    }
    int val = 0;
    for(int i = 0;i<mx;++i){
        if(n&(1ll<<i))val+=(1ll<<i);
    }
    cout << n+((1ll<<mx)-val) << endl;
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