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


int x,c,y,b,k;
int contrib(int t, vector<int>&a){
    // contribtion of the first t tickets
    int res = 0;
    int pos = 0;
    int lcm = (c*b)/__gcd(c,b);
    vector<bool>taken(t);
    for(int i = lcm-1;i<t;i+=lcm){
        res+=((x+y)*(a[pos]/100));
        taken[i] = 1;
        pos++;
    }
    for(int i = c-1;i<t;i+=c){
        if(taken[i])continue;
        taken[i] = 1;
        res += ((x) * (a[pos] / 100));
        pos++;
    }
    for(int i = b-1;i<t;i+=b){
        if(taken[i])continue;
        res+=((y)*(a[pos]/100));
        pos++;
    }

    return res;
}

bool pos(vector<int>&a, int t){
    return contrib(t,a)>=k;
}

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    
    for(int &u :a)cin >> u;
    cin >> x >> c >> y >> b;
    if(y > x){
        swap(x,y);
        swap(c,b);
    }

    sort(all(a),greater<int>());
    cin >> k;

    int l = 0,r = n;
    while(l+1 < r){
        int m = (l+r)/2;
        if(pos(a,m))r = m;
        else l = m;
    }
    if(contrib(r,a)>=k)cout << r << endl;
    else cout << -1 << endl;
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