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
    int n,k;
    cin >> n >> k;
    vector<int>a(n+1);
    int start = (n+1)/2, gap = 1;
    if(k==1){
        for(int i= 1;i<=n;++i)cout << i << ' ';
        cout << endl;
        return;
    }
    for(int i = 1;i<=k;++i){
        a[i] = start;
        if(i%2)start+=gap,gap++;
        else start-=gap,gap++;
    }
    if(a[k] < (n+1)/2){
        start = a[k];
        for(int i = k+1;i<=n;++i){
            if(start<=1)break;
            start--;
            a[i] = start;
            
        }
        int get = 0;
        for(int i = 1;i<=k;++i)get = max(get,a[i]);
        get++;
        for(int i =k+1;i<=n;++i){
            if(a[i]==0)a[i] = get,get++;
        }
    }else{
        start = a[k];
        for(int i= k+1;i<=n;++i){
            if(start>=n)break;
            start++;
            a[i] = start;
        }
        int get = 1e18;
        for(int i = 1;i<=k;++i)get = min(get,a[i]);
        get--;
        for(int i = k+1;i<=n;++i){
            if(a[i]==0)a[i] = get,get--;
        }
    }
    for(int i = 1;i<=n;++i)cout << a[i] << ' ';
    cout << endl;
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