#include <bits/stdc++.h>
 
#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
using namespace std;
 
void solve() {
  int m;
  cin >> m;
  vector<int> n(m), l(m), r(m);
  vector<vector<int>> a(m);
  vector<vector<int>> c(m);
  vector<int> sumc(m);
  int suml = 0, sumr = 0, sumn = 0;
  for (int i = 0; i < m; i++) {
    cin >> n[i] >> l[i] >> r[i];
    sumn += n[i];
    suml += l[i];
    sumr += r[i];
    a[i].resize(n[i]);
    for (int j = 0; j < n[i]; j++) {
      cin >> a[i][j];
    }
    c[i].resize(n[i]);
    for (int j = 0; j < n[i]; j++) {
      cin >> c[i][j];
      sumc[i] += c[i][j];
    }
  }
  
  if (sumr - suml > sumn) {
    cout << "0\n";
    return;
  }
 
  map<int, int> sumr_a;
  map<int, vector<pair<int, int>>> indexes;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n[i]; j++) {
      sumr_a[a[i][j]] += r[i];
      indexes[a[i][j]].pb({i, j});
    }
  }
 
  int ans = (int) 2e18;
  for (int len = suml; len <= sumr; len++) {
    int xsize = 0, must_len = 0;
    xsize += sumr - sumr_a[len];
    for (auto &[i, pos] : indexes[len]) {
      int cnt_not_len = sumc[i] - c[i][pos];
      if (cnt_not_len < l[i]) {
        xsize += l[i];
        must_len += l[i] - cnt_not_len;
      } else {
        xsize += min(cnt_not_len, r[i]);
      }
    }
    ans = min(ans, must_len + max(0LL, len - xsize));
  }
  cout << ans << '\n';
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
