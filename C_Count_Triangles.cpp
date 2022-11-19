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


int f(int a, int n){
    return (n*(2*a + (n-1)))/2;
}
void solve()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    // x+ y > z
    int pos = c;
    int tot = 0;
    vector<int>sum(1e6+5);
    int start = 1;
    for(int i = 1;i<=(int)(1e6);++i){
        sum[i] = sum[i-1]+start;
        start++;
        if(start >= (c-b+1))start = c-b+1;
    }
    int res = 0;
    for(int i = d;i>=c;--i){
        int req = i-a+1;
        tot = 0;
        if(req > c){
            int first = a+(req-c);
            if(first > b){
                continue;
            }
            int rem = b-first+1;
            tot+=(sum[rem]);
        }else if(req < b){
            tot+=((b-a+1)*(c-b+1));
        }else{
            int first = c-req+1;
            int terms = b-a+1;
            // 3 + 4 + 5 + 6.. 
            int val = sum[first+terms-1] - (first>=1?sum[first-1]:0);
            tot+=val;
        }
        dbg(tot);
        res+=tot;
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
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}