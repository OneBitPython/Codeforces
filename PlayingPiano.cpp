//https://codeforces.com/contest/1032/problem/C
#include <bits/stdc++.h>
using namespace std;

int a[105];
map <int, int> t;
int main (){
    int n, k, m = 0, x = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> a[i];       
    for (int i = 0; i < n; i ++){
        if (t[a[i]] == 0) x ++;
        t[a[i]] ++;
        m = max (m, t[a[i]]);
    }
    cout << (m - 1 + k) / k * k * x - n << endl;
    return 0;
}
