// https: //codeforces.com/problemset/problem/4/C

#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;
void solve(){
    string user;
    cin >> user;
    if (mp[user]==0){
        mp[user]+=1;
        cout << "OK" << endl;
    }else{
        cout << user<< mp[user] << endl;
        mp[user]++;
    }
}

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        solve();
    }
}