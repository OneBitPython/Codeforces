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

struct CHT{
 
    // dq[i].first  stores a line represeting the point
    // dq[i].second stores the intersection between two adjacent lines
    struct line{
        int m,c;
        line(int m, int c) : m(m), c(c) {}
 
        int intersect(line l2){
            /*
            y = m1x + c1
            y = m2x + c2
            m1x + c1 = m2x + c2
            m1x-m2x = c1-c1
            x(m1-m2) = c2 - c1
            x = (c2-c1)/(m1-m2)
            */
            int first = l2.c - c, second = m-l2.m;
            return (first/second)+(first%second==0?0:1);
        }
        int val(int x){
            return m*x + c;
        }
    };  
    deque<pair<line,int>>dq;
    void insert(int m, int c){
        line l{m,c};
        while(dq.size() > 1 && l.intersect(dq.back().first)<=dq.back().second)dq.pop_back();
        if(dq.size()==0){
            dq.push_back({l,0});
            return;
        }
        dq.push_back({l,l.intersect(dq.back().first)});
    }
    
    int query(int x){
        int l = 0, r = dq.size();
        while(l + 1 < r){
            int m = (l+r)/2;
            if(dq[m].second <= x)l = m;
            else r = m;
        }
        return dq[l].first.val(x);
        
    }
};


void solve()
{
    int n; 
    cin >> n;
    vector<vector<int>>a(n+1,vector<int>(3));
    for(int i = 1;i<=n;++i)cin >> a[i][0] >> a[i][1] >> a[i][2];
    /*
    dp[io] = dp[j]+(x[i]*y[i])-(x[j]*y[i])-a[i]
    dp[j] = c
    -x[j] = m
    y[i] = x
    */
    CHT cht;
    sort(all(a));
    vector<int>dp(n+1);
    int res = 0;
    cht.insert(a[0][0], 0);
    for (int i = 1; i <= n; ++i) {
      dp[i] = cht.query(a[i][1]) + a[i][2] - (a[i][0] * a[i][1]);
      cht.insert(a[i][0], -dp[i]);
      res = max(res, dp[i]);
    }
    dbg(dp);
    cout << res;
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