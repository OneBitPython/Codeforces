#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int z=0;z<t;z++){
        int n,a[20],b[20],x,count,c,d,count1=0,e[20];
        for(int i=0;i<n;i++){
            cin >> x;
            a[i]=x;
            b[i]=x;
            e[i]=x;
        }
        sort(b[0],b[n]);
        for(int i=0;i<n;i++){
            if(a[i]==b[i]) count++;
        }
        if(count==n) {cout << "YES"; break;}
        for(int i=0;i<6;i++){
            c=pow(2,i+1)-1;
            d=pow(2,i+2)-1;
            sort(e[c],e[d]);
            for(int j=c;j<=d;j++){
                if(a[j]==e[j]) count1++;
            }
        }
        if(count1==n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}