#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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
vector<double> pos, speed;
bool ok(double x){
    // distance = speed * time
    // person i can travel upto speed[i]*x distance forwards or backwards
    // ie in the range pos[i] + (speed[i]*x) or pos[i] - (speed[i] * x)
    // check if all ranges intersect at a single point

    /*
    1,5
    4,8
    a,b,c,d
    if(c<=b && c>=a) or a<=d && a>=c or (b>=c && b<=d) then intersection occurs. intersected area is (min(a,c), max(b,d))
    */
    double a = pos[0]-(speed[0]*x);
    double b = pos[0] + (speed[0] * x);
    for(int i = 1;i<n;++i){
        double c = pos[i] - (speed[i] * x);
        double d = pos[i] + (speed[i] * x);
        if((c<=b && c>=a) || (d<=b && d>=a) || (a<=d && a>=c) || (b>=c && b<=d)){
            // intersection occurs
            a = max(a,c);
            b = min(b,d);
        }else return 0;
    }
    return 1;
}

void solve()
{
    cin >> n;
    speed.resize(n);
    pos.resize(n);
    for(double &u : pos)cin >> u;
    for(double &u :speed)cin >> u;
    double x = 125000000000000000;
    double l = 0, r = 1e18;
    for(int i = 0;i<100;++i){
        double m = (l+r)/2;
        if(ok(m))r = m;
        else l = m;
    }
    cout << fixed << setprecision(12) << r << endl;
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