#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s[2];

    int n = 2;
    int m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        m = s[i].length();
    }

    int ans = 0;
    int previous = 0;
    for (int i = 0; i < m; i++)
    {
        int current = (s[0][i] == '0') + (s[1][i] == '0');

        if (current == 0)
            previous = 0;

        if (current == 1)
        {
            if (previous == 2)
            {
                ans++;
                previous = 0;
            }
            else
                previous = 1;
        }

        if (current == 2)
        {
            if (previous > 0)
            {
                ans++;
                if (previous == 2)
                    previous = 1;
                else
                    previous = 0;
            }
            else
                previous = 2;
        }
    }

    cout << ans;
}
