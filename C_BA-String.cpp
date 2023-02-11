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
    int n,k,x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<int>c;
    int sz = 0;
    string t;
    for(int i = 0;i<n;++i){
        if(s[i]=='*')sz++;
        else{
            if(sz)t+="*";
            t+=s[i];
            if(sz)c.pb(k*sz+1);
            sz = 0;
        }
    }
    if(sz)c.pb(k*sz+1),t+="*";
    int m = c.size();
    vector<int>times(m);
    while(x>1){
        int p = 1;
        for(int i = m-1;i>=0;--i){
            if((unsigned long long)(p*c[i]) >= x){
                int val = (x+p-1)/p;
                times[i] = val-1;
                x-=(times[i]*p);
                break;
            }else p*=c[i];
        }
    }
    string res;
    int pos = 0;
    for(int i = 0;i<(int)(t.size());++i){
        if(t[i]=='*'){
            for(int j = 0;j<times[pos];++j)res+="b";
            pos++;
        }else res+="a";
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