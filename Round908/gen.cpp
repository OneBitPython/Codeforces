#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl "\n"
#define all(c) c.begin(), c.end()

int rand(int a, int b){
	return a+rand()	% (b-a+1);
}
/*
1
9 9
9 6 10 10 3 3 10 6 5 
3 2 1 6 3 7 3 8 3 
*/
int main(int argc, char* argv[])
{

	srand(atoi(argv[1]));
 	int n = rand(1,8);
    int m = rand(1,4);
    cout << 1 << endl;
 	cout << n << ' ' << m << endl;
	for(int i = 0;i<n;++i){
		int x = rand(1,10);
		cout << x << ' ';
	}
    cout << endl;
    for(int i = 0;i<m;++i){
		int x = rand(1,10);
		cout << x << ' ';
	}
}

