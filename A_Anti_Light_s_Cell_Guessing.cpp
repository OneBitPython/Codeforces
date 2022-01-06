#include <bits/stdc++.h>
using namespace std;



void solve()
{
    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0 || n==1 && m==1)
    {
        cout << 0 << endl;
    }
    else if (n == 1 || m == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
}