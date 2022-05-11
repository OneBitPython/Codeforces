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
    int n,m;
    cin >> n >> m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j)cin >> a[i][j];
    }
    int best = 0;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            int res = a[i][j];
            int x = i,y = j;
            int x1 = i, y1 = j;
            int x2 = i, y2 = j;
            int x3 = i, y3 = j;
            for(int k = 1;k<=1000;++k){
                x++;
                y++;
                if(x>=n || y>=m)break;
                res+=a[x][y];
            }
            for (int k = 1; k <= 1000; ++k)
            {
                x1--;
                y1--;
                if (x1 <0 || y1<0)
                    break;
                res += a[x1][y1];
            }
            for (int k = 1; k <= 1000; ++k)
            {
                x2--;
                y2++;
                if (x2 < 0 || y2 >= m)
                    break;
                res += a[x2][y2];
            }
            
            for (int k = 1; k <= 1000; ++k)
            {
                x3++;
                y3--;
                if (x3 >=n || y3 < 0)
                    break;
                res += a[x3][y3];
            }

            best = max(best, res);
        }
    }
    cout << best<< endl;
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
        solve();
    }
}