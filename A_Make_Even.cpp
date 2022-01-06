#include <bits/stdc++.h>
using namespace std;

void solve(){
    string n;
    cin >> n;
    int value=-1;
    for (int i=0;i<n.size();++i){
        if (n[i]%2 == 0){
            value = i;
            break;
        }
        
    }
    if (n[n.size()-1]%2==0){
        cout << 0 << endl;
    }else{
        if (value==-1){
            cout << -1 << endl;
        }else if (n[0]%2==0){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
}
int main(){
    int T;
    cin >> T;

    while(T--){
        solve();
    }
}