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


int n,d;
bool pos(int x,vector<int>a){
    vector<int>gaps(n+1); // gaps[i] stores gap between a[i] and a[i+1]
    for(int i =0;i<n;++i){
        int space = a[i+1]-a[i]-1;
        int get = (space-1)/2;
        if(get>=x)gaps[i] = a[i]+get+1;
        else gaps[i]=-1;
    }
    bool ok = 1;
    vector<int>b = a;
    for(int i = 1;i<=n;++i){
        if(a[i]-a[i-1]-1 < x){
            ok = 0;
            if(i < n){
                int space = a[i+1]-a[i-1]-1;
                int get = (space-1)/2;
                if(get>=x){
                    a[i] = a[i-1]+get+1;
                    break;
                }
            }
            bool move = 0;
            for(int j = 0;j<i-1;++j){
                if(gaps[j]!=-1){
                    a[i] = gaps[j];
                    move = 1;
                    break;
                }
            }
            if(move)break;
            for(int j = i+1;j<n;++j){
                if(gaps[j]!=-1){
                    a[i] = gaps[j];
                    move = 1;
                    break;
                }
            }
            if(!move)a[i] = d;
            break;
        }
    }
    sort(all(a));
    if(ok)return 1;
    ok = 1;
    for(int i= 1;i<=n;++i){
        if(a[i]-a[i-1]-1 < x){
            ok = 0;
            break;
        }
    }
    if(ok)return 1;
    for(int i = 1;i<n;++i){
        if(b[i+1]-b[i]-1 < x){
            // change b[i]
            int space = b[i+1]-b[i-1]-1;
            int get = (space-1)/2;
            if(get >= x){
                b[i] = b[i-1]+get+1;
                break;
            }
            bool move = 0;
            for(int j = 0;j<i-1;++j){
                if(gaps[j]!=-1){
                    b[i] = gaps[j];
                    move = 1;
                    break;
                }
            }
            if(move)break;
            for(int j = i+1;j<n;++j){
                if(gaps[j]!=-1){
                    b[i] = gaps[j];
                    move = 1;
                    break;
                }
            }
            if(!move)b[i] = d;
            break;
        }
    }
    sort(all(b));
    
    for(int i= 1;i<=n;++i){
        if(b[i]-b[i-1]-1 < x){
            return 0;
        }
    }
    return 1;
}
void solve()
{
    cin >> n >> d;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    int res = 0;
    int l = 0, r = d-1;
    while(l <= r){
        int m = (l+r)/2;
        if(pos(m,a))res = m, l = m+1;
        else r = m-1;
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