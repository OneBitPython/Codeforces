#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;

    string comp = s;
    sort(comp.begin(), comp.end());

    string ans = "";
    int size = 0;
    for(int i = 0; i < s.size(); i++){
        if (comp[i] != s[i]){
            ans+=to_string(i+1) + " ";
            size+=1;
        }
    }
    if (ans.size() > 1){
        cout << 1 << endl;
        cout << size << " " << ans;
    }else{
        cout << 0;
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;

    for(int i = 0; i <T; ++i){
        solve();
    }
}