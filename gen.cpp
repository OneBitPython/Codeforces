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
	int t = 100;
	cout << t << endl;
	for(int i= 1;i<=t;++i){
		int n = rand(3,100);
		cout << n << endl;
		for(int j = 1;j<=n;++j){
			int x = rand(1,3);
			int l = rand(1,8), r = rand(l,8);
			cout << x << ' ' << l << ' ' << r << endl;
			for(int k = 1;k<=x;++k)cout << rand(1,8)  << ' ';
			cout << endl;
			for(int k = 1;k<=x;++k)cout << rand(1,3) << ' ';
			cout << endl;
		}
	}

}

