#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    set<int> s;
    int G;
    for (int i = 0; i < n; i++){
        cin >> G;
        s.insert(G);
    }
    vector<int> vec(s.begin(), s.end());
    if (vec.size()>=2){
        cout << vec[1] << endl;
    }else{
        cout << "NO" << endl;
    }
}