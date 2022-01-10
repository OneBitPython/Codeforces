#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr;
        map<int,int>mp;
        for(int i=0;i<n;++i){
            int x ;
            cin >> x;
            while(x>n){
                x/=2;
            }
            if(x<=n){
                while(mp.find(x)!=mp.end()){
                    x/=2;
                }
                if(x >0 && mp.find(x)==mp.end()){
                    mp[x]=1;
                }
            }

        }
        cout << (mp.size()==n?"YES":"NO") << endl;
    }
}