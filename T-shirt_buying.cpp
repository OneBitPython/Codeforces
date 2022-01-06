#include <bits/stdc++.h>
using namespace std;

void solve(){
    int num_shirts,num_customers,tmp;
    cin >> num_shirts;
    vector<int> prices(num_shirts),fore_type;
    map<int,vector<pair<int,int>>> mp;

    for(int i = 0; i < num_shirts;++i){
        cin >> prices[i];
    }
    for(int i = 0; i < num_shirts;++i){
        cin >> tmp;
        fore_type.push_back(tmp);
        mp[tmp].push_back({prices[i],i});
    }
    for (int i = 0; i < num_shirts; ++i)
    {
        cin >> tmp;
        if (tmp!=fore_type[i]){
            mp[tmp].push_back({prices[i], i});
        }
    }
    sort(mp[1].begin(), mp[1].end());
    sort(mp[2].begin(), mp[2].end());
    sort(mp[3].begin(), mp[3].end());

    cin >> num_customers;
    int cust_pref;
    for(int i = 0; i < num_customers;++i){
        cin >> cust_pref;
        if (mp[cust_pref].empty()==1){
            cout << -1 << " ";
        }else{
            cout << mp[cust_pref].front().first << " ";
            mp[cust_pref].erase(mp[cust_pref].begin()+1);
        }
    }
    // int possible_price=INT_MAX,possible_price_idx=0;
    // bool flag=true;
    // for (int cust_prefer : customers){
    //     for(int i = 0; i < prices.size();++i){
    //         if(colors[i].first==cust_prefer || colors[i].second==cust_prefer){
    //             if (prices[i]<=possible_price){
    //                 possible_price=prices[i];
    //                 possible_price_idx = i;
    //                 flag=false;
    //             }
    //         }
    //     }
    //     if (flag){
    //         cout << -1 << " ";

    //     }
    //     else{
    //         colors.erase(colors.begin() + possible_price_idx);
    //         prices.erase(prices.begin()+possible_price_idx);
    //         cout << possible_price << " ";
    //         flag=true;
    //         possible_price = INT_MAX;
    //     }

    // }
}

int main(){
    solve();
}