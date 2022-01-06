#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int nextPowerOf2(int n) 
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}
int32_t main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed;
    cout<<setprecision(10);

    int t;
    cin >> t;
    for (int i = 0; i <t; i++){
        int n, k;
        cin >> n >> k;
        if (n==2){
            cout << 1 << endl;
        }else{
        int v;
        if (k==1){
            cout << ceil(n-1/k) << endl;
        }else{
            if (k>=n){
                v = nextPowerOf2(n-1);
            }else{
                v = nextPowerOf2(k+1);
            }
            double one = (log((v + (log(v) /
                    log(2))))) / log(2);
            if (v < n){
                int adder = (n-v)%k == 0 ? 0 : 1;
                one+=((n-v)/k) + adder;
            }
            cout << (int)one << endl;
        }
        }
    }
} 
