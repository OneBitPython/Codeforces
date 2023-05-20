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
	cout << 1 << endl;
 	int n = rand(1,100);
	cout << n << endl;
	for(int i = 1;i<=n;++i)cout << rand(1,n) << ' ';
}

