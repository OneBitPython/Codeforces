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


vector<int>a;
int n;
bool pos(int x){
    int cnt = 0;
    for(int i = 1;i<=n;++i){
        int val = x-a[i];
        if(val < 0)return 0;
        if((n-i) > val || ((i-1) > val))cnt++;
    }
    return cnt <= 1;
}
void solve()
{
    cin >> n;
    a.resize(n+1);
    for(int i =1 ;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=1000;++i){
        for(int j = 1;j<=n;++j){
            int att = i;
            int l = j, r = j;
            bool ok = 1;
            int curr = j;
            while(1){
                if(a[curr] < att){
                    ok = 0;
                    break;
                }
                att--;
                
                if(l==1 && r == n)break;
                if(l==1){
                    curr = r+1;
                    r++;
                }else if(r == n){
                    curr = l-1;
                    l--;
                }else{
                    if(a[l-1] < a[r+1]){
                        curr = l-1;
                        l--;
                    }else{
                        curr = r+1;
                        r++;
                    }
                }
            }
        }
    }
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