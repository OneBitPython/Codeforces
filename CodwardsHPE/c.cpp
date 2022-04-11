#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}


int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n){
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        val+="1";
      }
      else
      {
        val+="0";
      }
    }
    while(val.front()=='0'){
        val.erase(0,1);
    }
    return val;
}




void solve()
{
    string s;
	cin>>s;
	int n =s.size();
	int comp = stoll(s);
	if(n == 1 || n == 2){
		cout << s << endl;
		return;
	}
	if(s.size()>10){
		int check = s[0]-'0';
		
		bool ok = 1;
		for(auto x : s){
			if((x-'0')>check){
				ok = 0;
				break;
			}
			if((x-'0')<check)break;
		}
		if(ok){
			string res;
			for(int i = 0;i<s.size();++i){
				res+=s[0];
			}
			cout << res  << endl;
		}else{
			if(check == 9){
				string res = "1";
				for(int i = 0;i<s.size();++i)res+='1';
				cout << res << endl;
			}else{
				string res;
				char val = '0'+((s[0]-'0')+1);
				for(int i = 0;i<s.size();++i){
					res+=val;
				}
				cout << res << endl;
			}
		}
		
	}else{
		vector<int>alls;
		for(int v = 1;v<=9;++v){
			for(int diff = -9;diff<=9;++diff){
				string res;
				int i = 0;
				bool ok = 1;
				int val = v;
				while(i<n){
					res+=(val+'0');
					if(val< 0 || val > 9){
						ok = 0;
						break;
					}
					val+=diff;
					
					i++;
				}
				if(ok){
					int c = stoll(res);
					if(c>=comp)alls.pb(c);
				}
			}
		}
		sort(all(alls));
		cout << alls[0] << endl;
	}
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    // int i = 1;
    while (T--)
    {
        solve();
    }
}