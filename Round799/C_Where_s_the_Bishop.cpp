#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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
    int n = 8, m = 8;
    vector<vector<char>>a(n, vector<char>(m));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j)cin >> a[i][j];
    }
    for(int i = 1;i<n-1;++i){
        for(int j = 1;j<m-1;++j){
            // check if a[i][j] is possible for bshop
            if(a[i][j]!='#')continue;
            bool ok = 1;
            int x = i, y = j;
            for(int k = 1;k<9;++k){
                x++;
                y++;
                if(x >= 8 || y >= 8)break;
                if(a[x][y]!='#')ok = 0;
            }
            x = i, y = j;
            for(int k = 1;k<9;++k){
                x--;
                y++;
                if(x < 0 || y >= 8)break;
                if(a[x][y]!='#')ok = 0;
            }
            x = i, y = j;
            for(int k = 1;k<9;++k){
                x--;
                y--;
                if(x < 0 || y < 0)break;
                if(a[x][y]!='#')ok = 0;
            }
            x = i, y = j;
            for(int k = 1;k<9;++k){
                x++;
                y--;
                if(x >= 8 || y < 0)break;
                if(a[x][y]!='#')ok = 0;
            }
            if(ok){
                cout << i+1 << ' ' << j+1 << endl;
                return;
            }
        }
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
        // cout << "Case #" << i << ": ";
        solve();
    }
}