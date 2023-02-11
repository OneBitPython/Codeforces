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

int querya(int i, int j){
    cout << "and " << i << ' '<< j << endl;
    int ret;
    cin >> ret;
    return ret;
}
int queryo(int i, int j){
    cout << "or " << i << ' '<< j << endl;
    int ret;
    cin >> ret;
    return ret;
}
void solve()
{
    int n,k;
    cin>> n >> k;
    /*

    */
    int and12 = querya(1,2), and13 = querya(1,3), or12 = queryo(1,2), or13 = queryo(1,3), and23 = querya(2,3);
    vector<int>a(n+1);
    for(int i = 0;i<=30;++i){
        if((and12&(1ll<<i))){
            a[1]+=(1ll<<i);
            a[2]+=(1ll<<i);
        }else{
            if(or12&(1ll<<i)){
                // ith bit is set in either 1 or 2
                if((or13&(1ll<<i)) == 0){
                    a[2]+=(1ll<<i);
                }else{
                    // could be set in both 2,3 or only 1
                    if(and23&(1ll<<i)){
                        a[2]+=(1ll<<i);
                        a[3]+=(1ll<<i);
                    }else a[1]+=(1ll<<i);
                }
            }
        }

        if((and13&(1ll<<i))){
            a[3]+=(1ll<<i);
        }else{
            if(or13&(1ll<<i)){
                // ith bit set in either 1 or 3
                if((or12&(1ll<<i)) == 0)a[3]+=(1ll<<i);
            }
        }
    }
    for(int i = 4;i<=n;++i){
        int an = querya(1,i);
        int orr = queryo(1,i);
        for(int j = 0;j<=30;++j){
            if(an&(1ll<<j))a[i]+=(1ll<<j);
            else{
                if(orr&(1ll<<j)){
                    // set in 1 or i
                    if((a[1]&(1ll<<j)) == 0)a[i]+=(1ll<<j);
                }
            }
        }
    }   
    sort(a.begin()+1, a.end());
    cout << "finish " << a[k] << endl;
}   

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