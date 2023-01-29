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


struct CHT {
    struct Line {
        long long m, c;
        Line(long long x, long long y) {
             m = x;
             c = y;
        }
        long double Intersect(Line a) {
            return (long double)((a.c - c + m - a.m - 1) / (m - a.m));
        }
        long long Evaluate(long long x) {
            return m * x + c;
        }
    };
    deque<pair<Line, long double> > dq;

    void insert(long long m, long long c) {
        Line cur = Line(m, c);
        while(dq.size() > 1 && dq.back().first.Intersect(dq[dq.size() - 2].first) >= dq.back().first.Intersect(cur)) {
            dq.pop_back();
        }
        //cout << "Insert function" << endl;
        if(dq.size() == 0) {
            dq.push_back({cur, 0});
        }
        else {
            //cout << "dq.back().first.m = " << dq.back().first.m << endl;
            dq.push_back({cur, dq.back().first.Intersect(cur)});
        }
    }

    long long QueryMonotonic(long long x) {
        while(dq.size() > 1 && dq.front().first.Evaluate(x) <= dq[1].first.Evaluate(x)) {
            dq.pop_front();
        }
        return dq.front().first.Evaluate(x);
    }

    long long query(long long x) {
        auto ans = *lower_bound(dq.rbegin(), dq.rend(), make_pair(Line(0, 0), x), [&](const pair<Line, long double> &a, const pair<Line, long double> &b) {
            return a.second > b.second;
        });
        //cout << "QueryNormal: x = " << x << ", ans.first.Evaluate(x) = " << ans.first.Evaluate(x) << ", ans.first.m = " << ans.first.m << endl;
        return ans.first.Evaluate(x);
    }
};
void solve()
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
    dp[0] = (x[0]*y[0]) - a[0];
    int res = dp[0];
    cht.insert(x[0],-dp[0]);

    for(int i = 1;i<n;++i){
        dp[i] = max(0ll, (x[i]*y[i])-a[i]);
        int m = -cht.query(y[i]);
        if(m>0)dp[i]+=m;
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