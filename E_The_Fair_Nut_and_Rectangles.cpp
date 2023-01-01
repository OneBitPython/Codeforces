#include <bits/stdc++.h>
using namespace std;

#define int long long
#define intl __int128
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


struct CHT{
    struct line{
        intl m,c;
        line(intl a, intl b){
            m = a;
            c = b;
        }
        int intersect(line l){
            int first = l.c - c;
            int second = m-l.m;
            return (first/second)+(first%second?1:0);
        }
        intl operator()(intl x){
            return m*x+c;
        }
    };
    vector<line>cht;
    bool check(line a, line b, line c) // int of a and c is behind int of a and b
    {
        intl v1 = (c.c-a.c)*(b.m-c.m);
        intl v2 = (c.c-b.c)*(a.m-c.m); 
        return v1<=v2;
    }

    void insert(intl m, intl c){
        line l(m,c);
        if(cht.empty()){
            cht.pb(l);
            return;
        }
        int z = cht.size();
        while((cht.size()-1) && check(l,cht[z-1],cht[z-2]))
        {
            cht.pop_back();
            z--;
        }
        cht.pb(l);

    }
    int query(int x){
        int l = 0, r = cht.size()-1;
        if(r==0){
            return cht[0](x);
        }
        while(l + 1 < r){
            int m = (l+r)/2;
            int ma = cht[m].m, mb = cht[m+1].m;
            int ca = cht[m].c, cb = cht[m+1].c;
            if((x*(ma-mb))>=(cb-ca))l = m+1;
            else r = m;
        }
        return min(cht[l](x), cht[r](x));
    }
};void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>b(n, vector<int>(3));
    for(int i = 0;i<n;++i)cin >> b[i][0] >> b[i][1] >> b[i][2];
    vector<int>x(n), y(n), a(n);
    sort(all(b));
    for(int i = 0;i<n;++i){x[i] = b[i][0]; y[i] = b[i][1]; a[i] = b[i][2];}
    /*
    dp[i] = dp[j]+(x[i]*y[i])-(x[j]*y[i])-a[i]
    dp[j] = c
    -x[j] = m
    y[i] = x
    */
    CHT cht;
    vector<int>dp(n);
    dp[0] = (x[0]*y[0])-a[0];
    cht.insert(x[0],-dp[0]);
    int res = max(0ll,dp[0]);
    for(int i = 1;i<n;++i){
        dp[i] = (x[i]*y[i])-a[i];
        int m = -cht.query(y[i]);
        if(m > 0)dp[i]+=m;
        cht.insert(x[i],-dp[i]);
        res = max(res, dp[i]);
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}