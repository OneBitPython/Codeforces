#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
	return a+rand()	% (b-a+1);
}
int main(){
    srand(time(0));  
    int cnt0 = 0, cnt1 = 0;
        for(int i = 0;i<5;++i){
            if(rand(0,1) == 1)cnt1++;
            else cnt0++;
        }
        if(cnt1 >= cnt0)cout << "NO" << endl;
        else cout << "YES" << endl;
 	// cout << 1 << endl;
 	// int n = 4;
    // int m = 4;
 	// cout << n << ' ' << m << endl;
 	// for(int i = 0;i<n;++i){
    //     for(int j = 0;j<m;++j){
    //         int x = rand(0, 3);
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }
}