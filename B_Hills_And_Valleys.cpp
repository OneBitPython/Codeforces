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

bool f(int a, int b, int c){
    if((b > a && b > c) || (b < a && b < c))return 1;
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    int res = 0;
    for(int i = 1;i<n-1;++i){
        if(f(a[i-1],a[i],a[i+1]))res++;
    }

    if(n<=3){
        cout << 0 << endl;
        return;
    }
    
    int r2 = res;
    for(int i = 1;i<n-1;++i){
        int c = res;
        if(i >= 2){
            if(f(a[i-2],a[i-1],a[i]))c--;
        }
        // set a[i] to a[i-1]
        if(i < n-2){
            if(f(a[i],a[i+1],a[i+2]) && !f(a[i-1],a[i+1],a[i+2]))c--;
            if(!f(a[i],a[i+1],a[i+2]) && f(a[i-1],a[i+1],a[i+2]))c++;
        }
        if(f(a[i-1],a[i],a[i+1]))c--;
        r2 = min(r2, c);

        c = res;
        if(i < n-2){
            if(f(a[i],a[i+1],a[i+2]))c--;
        }
        // set a[i] to a[i+1]
        if(i >= 2){
            if(f(a[i-2],a[i-1],a[i]) && !f(a[i-2],a[i-1],a[i+1]))c--;
            if(!f(a[i-2],a[i-1],a[i]) && f(a[i-2],a[i-1],a[i+1]))c++;

        }
        if(f(a[i-1],a[i],a[i+1]))c--;
        r2 = min(r2, c);
    }
    

    cout << r2 << endl;
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