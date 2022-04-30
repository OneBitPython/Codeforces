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
    string x;
    cin >> x;
    string ac;
    for(int i = 0;i<x.size();++i){
        if(ac.empty() && x[i] == '0'){

        }else{
            ac+=x[i];
        }
    }
    int n = ac.size();
    int start = stoi(ac);
    start++;
    while(1){
        stringstream sss;
        sss<<start;
        string s = sss.str();
        n = s.size();
        for(int i = 0;i<n-1;++i){
            string num;
            for(int j = 0;j<=i;++j)num+=s[j];
            int number = stoi(num);
            int nxt = number+1;
            string curr;
            int tot = 1;
            bool ok = 1;
            for(int j = i+1;j<n;++j){
                if(curr.empty() && s[j] == '0'){
                    ok = 0;
                    break;
                }
                curr+=s[j];
                int int_curr = stoi(curr);
                if(int_curr == nxt){
                    curr.clear();
                    nxt++;
                    tot++;
                }
            }
            if(!ok)continue;
            if(curr.empty()){
                if(tot<=1)continue;
                cout << start << endl;
                return;
            }
        }
        start++;
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
    for(int i = 1;i<=T;++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}