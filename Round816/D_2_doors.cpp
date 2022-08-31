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
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a(m+1, vector<int>(3));
    for(int i = 1;i<=m;++i)cin >> a[i][0] >> a[i][1] >> a[i][2];
    sort(all(a), [&](auto one, auto two){
        return one[2] < two[0];
    });
    vector<int>res(n+1,-1);
    for(int i = 1;i<=m;++i){
        if(a[i][1] == a[i][0])res[a[i][0]] = a[i][2];
    }

    for(int i = 1;i<=m;++i){
        if(a[i][1] == a[i][0])continue;
        int x = res[a[i][0]];
        int y = res[a[i][1]];
        if(x==-1 && y == -1){
            if(a[i][0] < a[i][1]){
                res[a[i][0]] = 0;
                res[a[i][1]] = a[i][2];
            }else{
                res[a[i][1]] = 0;
                res[a[i][0]] = a[i][2];
            }
        }else if(y == -1){
            // x|something = a[i][2]
            int chose = 0;
            for(int j = 0;j<30;++j){
                if(a[i][2]&(1ll<<j)){
                    if(x&(1ll<<j))continue;
                    chose+=(1ll<<j);
                }
            }
            res[a[i][1]] = chose;
        }else if(x == -1){
            int chose = 0;
            for(int j = 0;j<30;++j){
                if(a[i][2]&(1ll<<j)){
                    if(y&(1ll<<j))continue;
                    chose+=(1ll<<j);
                }
            }
            res[a[i][0]] = chose;
        }
    }
    for(int i = 1;i<=n;++i)cout << max(0ll,res[i]) << ' ';
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}