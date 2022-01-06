#include <bits/stdc++.h>
using namespace std;
#define int signed long long

void solve(){
    int x, n;
    cin >> x >> n;
    int ans =x;
    if (n%4!=0){
        int rem = n%4;
        for(int i=n-rem+1; i<=n; i++){
            if(x%2==0){
                x-=i;
            }else{
                x+=i;
            }
        }
        ans = x;
    }
    cout <<ans << endl;
}

int32_t main(){
    int T;
    cin >> T;
    for(int i = 0; i <T; ++i){
        solve();
    }
}