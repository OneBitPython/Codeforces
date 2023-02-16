#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
// #define endl "\n"

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


int query(int l, int r){
    cout<< "? " << l << ' ' << r << endl;
    int ret;
    cin >> ret;
    return ret;
}
void solve()
{
    int n;
    cin >> n;
    int l = 1, r = n;
    int res = -1;
    int second = query(l,r);
    if(second != 1){
        if(query(1,second)==second){
            r = second;
            while(l <= r){
                int m = (l+(r-l)/2);
                if(second==m){
                    r = m-1;
                    continue;
                }
                int k = query(m,second);
                if(k==second)res = m, l = m+1;
                else r = m-1;
            }
            if(res==-1)res = r;
        }else{
            l = second;
            while(l<=r){
                int m = (l+(r-l)/2);
                if(second==m){
                    l = m+1;
                    continue;
                }
                int k = query(second, m);
                if(k==second)res = m, r = m-1;
                else l = m+1;
            }
            if(res==-1)res = l;
        }
    }else{
        l = second;
        while(l<=r){
            int m = (l+(r-l)/2);
            if(second==m){
                l = m+1;
                continue;
            }

            int k = query(second, m);
            if(k==second)res = m, r = m-1;
            else l = m+1;
        }
        if(res==-1)res = l;
    }
    cout << "! "  << res << endl;
}   
// 1 3 4 5 2
int32_t main()
{

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

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