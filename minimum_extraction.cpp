//https://codeforces.com/problemset/problem/1607/C
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

void solve(){
    int n;
    cin >> n;

    vector<signed long long> input(n);

    for(int i = 0; i < n;++i){
        cin >> input[i];
    }

    signed long long value;
    if (n>1){
        sort(input.begin(), input.end());
        vector<signed long long> output(n);
        int curr = 0;
        for(int i = 0; i < input.size();++i){
            output.push_back(input[i] - curr);

            curr+=input[i]-curr;
        }
        cout << *max_element(output.begin(), output.end()) << endl;
    }else{
        cout << input[0] << endl;
    }
}

int32_t main(){
    int T;
    cin >> T;

    for(int i=0; i< T; ++i){
        solve();
    }
}