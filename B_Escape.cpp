#include <bits/stdc++.h>
using namespace std;

int main(){
    double vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    if (vp >= vd)
    {
        cout << 0 << endl;
        exit(0);
    }

    int ans = 0;
    double ip = t * vp, dp = 0;
    while (ip < c)
    {
        double t_after_d_start = ip / (vd - vp);
        ip += t_after_d_start * vp;
        if (ip < c)
            ans++;
        double t_to_return = ip / vd;
        ip += t_to_return * vp;
        ip += f * vp;
    }
    cout << ans << endl;
}