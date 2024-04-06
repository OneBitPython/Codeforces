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
    int n,x,y;
    cin >> n >> x >> y;
    vector<int>a(x+1);
    for(int i = 1;i<=x;++i)cin >> a[i];
    sort(all(a));
    int Y = y;
    vector<int>oo,ee;
    for(int i =2;i<=x;++i){
        int xx = (a[i]-a[i-1]-1);
        if(xx%2)oo.pb(xx/2);
        else ee.pb(xx/2);
    }

    int xx = (n-a[x]+a[1]-1);

    if(xx%2)oo.pb(xx/2);
    else ee.pb(xx/2);
    sort(all(oo));
    for(auto val : oo){
        if(y>=val){
            y-=val;
            x+=(val+1);
        }else{
            x+=y;
            y = 0;
            break;
        }
    }
    for(auto val : ee){
        if(y>=val){
            y-=val;
            x+=(val);
        }else{
            x+=y;
            y = 0;
            break;
        }
    }
    cout <<Y+x-2-y << endl;
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