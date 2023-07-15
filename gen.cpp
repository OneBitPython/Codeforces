#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl "\n"
#define all(c) c.begin(), c.end()

int rand(int a, int b){
	return a+rand()	% (b-a+1);
}

int main(int argc, char* argv[])
{

	srand(atoi(argv[1]));
 	int n = rand(2,5);
	cout << n << endl;
	for(int i = 1;i<=n;++i){
		cout << rand(0,1) << ' ';
		for(int j = i+1;j<=n;++j)cout << rand(0,2) << ' ';
		cout << endl;
	}
}

