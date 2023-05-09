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
 	int n = rand(50,1000), k = rand(1,n);
	
 	cout << n << ' ' << k << endl;
	for(int i= 1;i<=k;++i){
		int t= rand(1,3);
		cout << t << ' ';
		int u = rand(1,n), v = rand(1,n);
		if(t==2){
			if(u > v)swap(u,v);

		}
		cout << u << ' ' << v << endl;
	}
	
}

