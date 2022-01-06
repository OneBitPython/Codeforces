#include <bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream& os, vector<int> &vec){
    reverse(vec.begin(), vec.end());
    for(auto val :vec){
        os << val << " ";
    }
    return os;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> input(N);
    for(int i=0; i<N; i++){
        cin >> input[i];
    }

    map<int, int> mp;
    int max_sequence_length = 0, max_number;
    for(int i = 0; i<input.size(); ++i){
        // if(mp.find(input[i]) == mp.end()){
        //     mp[input[i]] = 1;
        // }
        // if(find(input.begin(), input.begin()+i, input[i]-1)!=input.end()){
        //     mp[input[i]] = mp[input[i]-1]+1;
        //     if (mp[input[i]]>max_sequence){
        //         max_sequence = mp[input[i]];
        //         max_number = input[i];
        //     }
        // }
        mp[input[i]] = mp[input[i]-1]+1;
        if(mp[input[i]] > max_sequence_length){
            max_sequence_length = mp[input[i]];
            max_number = input[i];
        }
    }
    cout << max_sequence_length << endl;
    
    vector<int> ans;
    for(int i=input.size()-1; i>=0; --i){
        if (input[i]==max_number){
            max_number--;
            ans.push_back(i+1);
        }
    }
    cout << ans;
}