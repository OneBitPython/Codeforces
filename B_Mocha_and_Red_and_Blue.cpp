#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        int n;
        cin >> n;
        cin >> s;
        vector<char>values;
        for(auto  x : s){
            values.push_back(x);
        }
        if(find(all(values), 'B')==values.end() && find(all(values),'R') == values.end()){
            char last = 'B';
            for(int i=0;i<n;++i){
                cout << (last);
                last = last=='B'?'R':'B';
            }
            cout<<endl;
            
        }else{
        while(find(values.begin(),values.end(), '?')!=values.end()){
            for(int i=0;i<values.size();++i){
                if(values[i] == 'B'){
                    if(i==0){
                        if(values[i+1]=='?')values[i+1]='R';
                    }else if(i==n-1){
                        if(values[i-1]=='?')values[i-1]='R';
                    }else{
                        if(values[i-1]=='?')values[i-1]='R';
                        if(values[i+1]=='?')values[i+1]='R';
                    }
                }else if (values[i]=='R'){
                    if(i==0){
                        if(values[i+1]=='?')values[i+1]='B';
                    }else if(i==n-1){
                        if(values[i-1]=='?')values[i-1]='B';
                    }else{
                        if(values[i-1]=='?')values[i-1]='B';
                        if(values[i+1]=='?')values[i+1]='B';
                    }
                }
            }
        }
        for(auto x : values)cout << x;
        cout << endl;
        }
    }
}