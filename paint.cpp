#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n),increment(n);
    for(int i=0;i<n;++i) cin >> arr[i];
    for(int i=0;i<n;++i) cin >> increment[i];

    vector<pair<int,int>> combined;
    for(int i=0;i<n;++i){
        combined.push_back(make_pair(arr[i], increment[i]));
    }
    sort(combined.begin(),combined.end(),[](auto one, auto two){
        if(one.second == two.second)return one.first > two.first;
        return one.second > two.second;
    });
    
    int ans = 0;
    for(int i=0;i<n;++i){
        ans+=(combined[i].first + (combined[i].second * i));
    }
    cout << ans << endl;
}