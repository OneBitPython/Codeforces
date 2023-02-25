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

int desp(string &s, int x){
    s+=s;
    s+=s;
    int zero = 0, one = 0,res=0;
    for(int i = 0;i<(int)(s.size());++i){
        zero+=(s[i]=='0');
        one+=(s[i]=='1');
        if((zero-one) == x)res++;
    }
    return res;
}

void solve()
{
    int n,x;
    cin >> n >> x;
    string s;
    cin >> s;
    int one = count(all(s),'1'), zero = n-one;
    int t=0,y=0;
    for(int i = 0;i<n;++i){
        if(s[i]=='1')t++;
        else y++;
        if(y-t==x && zero-one==0){
            cout << -1 << endl;
            return;
        }
    }
    int res = 0;
    if(x==0)res++;
    int p = 0;
    for(int i = 0;i<n;++i){
        if(s[i]=='0')p++;
        else p--;
        bool ok = 0;
        if((x>=p) && zero>=one)ok = 1;
        if((x<=p)&&zero<=one)ok = 1;
        if(zero-one==0){
            if(p==x)res++;
            continue;
        }
        if(ok && (x-p)%(zero-one) == 0){
            res++;
        }
    }
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