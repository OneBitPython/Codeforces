#include <bits/stdc++.h>
using namespace std;

void solve(){
    int p;
    cin >> p;
    int G;
    map<int,int>mp;
    
    int max=0,greatest=0;
    for (int i = 0; i < p*2; i++){
        cin >> G;
        if (mp[G]==0){
            mp[G]++;
            max++;
        }else{
            if (max>greatest){
                greatest=max;
            }
            max--;
        }
    }
    cout << greatest;
}

int main(){
    solve();
}