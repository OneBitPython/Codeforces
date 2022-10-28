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
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    vector<int>d = {a,b,c};
    sort(all(d));
    a = d[2];
    b = d[1];
    c = d[0];
    /*
    a + A = b + B
    a + C = c + C

    a-b = B - A
    a-c = C - A
    find values of B-A and C - A
    B + C -2A= B-A + C-A
    B + C - 2A = a-b + a-c

    B + C = n-A
    n-A -2A = a-b + a-c
    -3A = 2a - b - c - n
    A = (2a - b - c - n)/-3
    B = a-b + A
    C = a-c + A
    */
    int A = (2 * a - b - c - n)/-3;
    if((2*a-b-c-n)%3 != 0){
        cout << "NO" << endl;
        return;
    }
    int B = a-b + A;
    int C = a-c+A;
    cout << (A+B+C==n?"YES":"NO") << endl;
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