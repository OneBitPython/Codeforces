#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

long long get_rand()
{
    long long a = rand();
    long long b = rand();
    return a * (RAND_MAX + 1ll) + b;
}

//#define int long long
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

// const int intmin = -100000000000000000LL;
// const int intmax = 100000000000000000LL;
const int MOD = 1000000007;

vector<vector<int>> dp(5001, vector<int>(5001, 0)), psums(5001, vector<int>(5001, 0)); // floor, trips made

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    dp[a][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        psums[i][0] = psums[i - 1][0] + dp[i][0];
    }

    // ((((a % m) - (b % m)) % m) + m) % m
    for (int i = 1; i <= k; ++i) // trips
    {
        for (int j = 1; j <= n; ++j) // floor
        {
            if (j == b)
            {
                continue;
            }

            int an = 0;

            if (j < b)
            {
                an = (an % MOD + psums[j - 1][i - 1] % MOD) % MOD;
                int mid = ceil((j + b) / 2.0);
                mid--;
                an = (an % MOD + (((psums[mid][i - 1] % MOD - psums[j][i - 1]%MOD)%MOD)+MOD)%MOD)%MOD;
            }
            else
            {
                an = (an % MOD + (((psums[n][i - 1] % MOD - psums[j][i - 1] % MOD) % MOD)+MOD)%MOD) % MOD;
                int mid = floor((j + b) / 2.0);
                an = (an % MOD + (((psums[j - 1][i - 1] % MOD - psums[mid][i - 1] % MOD) % MOD)+MOD)%MOD) % MOD;
            }

            dp[j][i] = an % MOD;
        }
        for (int j = 1; j <= n; ++j)
        {
            psums[j][i] = (psums[j - 1][i] % MOD + dp[j][i] % MOD) % MOD;
            psums[j][i] %= MOD;
        }
    }

    cout << psums[n][k] % MOD << '\n';
}
