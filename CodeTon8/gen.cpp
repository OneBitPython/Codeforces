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
	int t = 1;
	cout << t << endl;
	for(int i= 1;i<=t;++i){
		int n = rand(4,10), x = rand(1,n);
        set<int>cc;
        for(int i = 1;i<=x;++i)cc.insert(rand(1,n));
        while(cc.size() < 2)cc.insert(rand(1,n));
        cout << n << ' ' << cc.size() <<' ' << rand(0,n-cc.size()) << endl;
        for(auto x : cc)cout << x << ' ';
        cout << endl;

	}

}

