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
    struct Line {
        int m, c;
        Line(int x, int y) {
             m = x;
             c = y;
        }
        int intersect(Line a) {
            // int first = l.c-c;
            // int second = m-l.m;
            // return first/second + min(1ll,first%second);
            return (long double)((a.c - c + m - a.m - 1) / (m - a.m));
        }
        int eval(int x) {
            return m * x + c;
        }
    };

    deque<pair<Line, int>>dq;
    void insert(int m, int c){
        Line l(m,c);
        while(dq.size()>1 && dq.back().second>=l.intersect(dq.back().first))dq.pop_back();
        if(dq.empty()){
            dq.push_back({l, 0});
            return;
        }
        dq.push_back({l, dq.back().first.intersect(l)});
    }

    int query(int x){
        auto ans = *lower_bound(dq.rbegin(), dq.rend(), make_pair(Line(0, 0), x), [&](auto &a, auto &b) {
            return a.second > b.second;
        });
        return ans.first.eval(x);
    }

};


void solve()
{
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    for(int &u : a)cin >> u;
    for(int &u : b)cin >> u;
    vector<int>dp(n);
    CHT cht;
    cht.insert(0, 0);
    for(int i = 0;i<n;++i){
        dp[i] = cht.query(a[i]);
        cht.insert(b[i], dp[i]);
    }
    cout << dp[n-1];
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