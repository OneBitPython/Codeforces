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

int f(int a, int b){
    stringstream ss;
    ss << a;
    string s,t;
    ss >> s;
    stringstream sss;
    sss << b;
    sss >> t;
    int t1 = 0, t2 = 0;
    for(int i = (int)(s.size())-1;i>=0;--i){
        if(s[i] == '0')t1++;
        else break;
    }
    for(int i = (int)(t.size())-1;i>=0;--i){
        if(t[i] == '0')t2++;
        else break;
    }
    if(t1 > t2)return a;
    else if(t1==t2)return max(a,b);
    else return b;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    int res = 1;
    int fives = 0, twos = 0;
    int x = n;
    int y = n;
    while(x % 5 == 0){
        x/=5;
        fives++;
    }
    while(y%2 == 0){
        y/=2;
        twos++;
    }
    int got = min(twos,fives);
    for(int i = min(twos,fives)+1;;++i){
        int req1 = i-fives;
        int req2 = i-twos;
        int val = 1;
        if(req1 > 0){
            val*=(pow(5,req1));
        }
        if(req2 > 0){
            val*=(pow(2,req2));
        }
        if(val <= m){
            int got = val;
            int times = m/got;
            got*=times;
            res = f(res, got*n);
        }else break;
    }
    if(res == 1)res = n*m;
    cout << res << endl;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}