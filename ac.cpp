#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n;
    cin >> n;

    vi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll x;
    cin >> x;
    
    for (ll i = 0; i < n; i++) {
        a[i] -= x;
    }

    ll l, r;
    l = r = 0;

    ll sum = 0;
    ll ans = 0;

    while(l < n) {
        bool found = false;
        while (r - l <= 3) {
            if (sum < 0 && r - l > 1) {
                ans++;
                found = true;
                break;
            }

            if (r - l < 3 && r < n) sum += a[r++];
            else
                break;
        }

        if(found) {
            l = r;
            sum = 0;
            continue;
        }

        sum -= a[l++];
    }

    cout << n - ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}