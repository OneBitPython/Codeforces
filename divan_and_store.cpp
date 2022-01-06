#include <bits/stdc++.h>
using namespace std;

void solve(){
    unsigned long long n,l,r,k;
    cin >> n >> l >> r >> k;

    vector<int>prices(n);
    for(int i=0; i<n;++i){
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    int budget_spent = 0;
    int ans=0;
    for (auto price : prices){
        int value = budget_spent+price;
        if (value > k){
            break;
        }
        if (price >=l && price <=r){
            budget_spent += price;
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        solve();
    }
}