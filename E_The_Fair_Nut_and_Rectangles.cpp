#include <bits/stdc++.h>
using namespace std;

#define int long long

constexpr int kInf = 1e9 + 10;
constexpr int kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;

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

    void Insert(long long m, long long c) {
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

    long long QueryNormal(long long x) {
        auto ans = *lower_bound(dq.rbegin(), dq.rend(), make_pair(Line(0, 0), x), [&](const pair<Line, long double> &a, const pair<Line, long double> &b) {
            return a.second > b.second;
        });
        //cout << "QueryNormal: x = " << x << ", ans.first.Evaluate(x) = " << ans.first.Evaluate(x) << ", ans.first.m = " << ans.first.m << endl;
        return ans.first.Evaluate(x);
    }
};


inline void solution() {
  int n;
  cin >> n;
  vector<vector<int>> a(n+1, vector<int>(3));
  for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
  /*
    dp[io] = dp[j]+(x[i]*y[i])-(x[j]*y[i])-a[i]
    dp[j] = c
    -x[j] = m
    y[i] = x
    */
  CHT cht;
  sort(a.begin(), a.end());
  vector<int> dp(n+1);
  cht.Insert(0, 0);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = cht.QueryNormal(a[i][1]) - a[i][2] + (a[i][0] * a[i][1]);
    cht.Insert(-a[i][0], dp[i]);
    res = max(res, dp[i]);
  }
  cout << res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}
