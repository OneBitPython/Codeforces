#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool b=false;
        for(int i=1;i<=sqrt(n);++i){
            int s = i*i;
            if(2*s == n || 4 * s == n){
                b = 1;
                cout << "YES" << endl;
            }
        }
        if(!b) cout << "NO" << endl;
    }
}