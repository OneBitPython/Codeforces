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
    int a, b, k;
    cin >> a >> b >> k;
    // a zeroes b ones
    b--;
    if(k>0 && (a+b-1)<k){
        cout << "No" << endl;
        return;
    }
    if(k>0 && ((a==0)||(b==0))){
        cout << "No" << endl;
        return;
    }
    string s = "1", t = "1";
    if(k>=1){
        s+="1";
        t+="0";
    }
    while(k>1){
        bool got = 0;
        if(a>1){
            s+="0";
            t+="0";
            a--;
            got = 1;
        }else{
            if(b>1){
                s+="1";
                t+="1";
                b--;
                got = 1;
            }
        }
        if(!got){
            cout << "No" << endl;
            return;
        }
        k--;
    }
    if(k>=1){
        s+="0";
        t+="1";
        a--;
        b--;
        k--;
    }
    while(b>0)s+="1",t+="1",b--;
    while(a>0)s+="0",t+="0",a--;
    cout << "Yes" << endl;
    cout << s << endl << t << endl;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}