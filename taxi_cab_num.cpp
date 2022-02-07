#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int gotill = cbrtl(n);
    unordered_set<int>taken;
    for(int i = 0;i<=gotill;++i){
        for(int j = 0;j<=gotill;++j){
            if(i!=j){
                int c1 = i*i*i;
                int c2 = j*j*j;

                if(c1+c2 == n && taken.count(c1)==0 && taken.count(c2)==0 && taken.size()<4){
                    taken.insert(i);
                    taken.insert(j);
                }
            }
        }
    }
    if(taken.size()==4){
        for(auto x : taken)cout << x << " ";
        
    }else cout << -1 << endl;
}