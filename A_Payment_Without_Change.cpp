#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,n,s;
        cin >> a >> b >> n >> s;
        int max_coins = s/(n);
        if(max_coins>a){
            max_coins = a;
        }
        if(b>=s){
            cout << "YES" << endl;return;
        }
        
        if(max_coins*n + b >=s){
            cout <<"YES" << endl;return;
        }else{
            cout << "NO" << endl;return;
        }
        
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();

    }
}