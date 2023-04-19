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
 	int n = rand(1,100);
    cout << 1 << endl;
 	cout << n << endl;
	for(int i = 0;i<n;++i){
		int x = rand(-100,100);
		cout << x << ' ';
	}
    cout<< endl;
    int x = rand(-100,100);
    cout << x << ' ';
}

