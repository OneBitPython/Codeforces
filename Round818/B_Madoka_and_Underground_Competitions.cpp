#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;


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

void f(vector<vector<char>>&a,int x, int y, int n){
    int x1 = x, y1 = y;
    while(1){
        if(x>n)break;
        if(y <1)break;
        a[x][y] = 'X';
        x++;
        y--;
    }
    while(1){
        if(x1<1)break;
        if(y1 > n)break;
        a[x1][y1] = 'X';
        x1--;
        y1++;
        
    }
}

void solve()
{
    int n,k,r,c;
    cin >> n >> k >>r >> c;
    vector<vector<char>>a(n+1, vector<char>(n+1, '.'));
    a[r][c] = 'X';
    for(int j = c;j>=1;j-=k){
        a[r][j] = 'X';
    }
    for(int j = c;j<=n;j+=k){
        a[r][j] = 'X';
    }
    for(int i = r;i>=1;i-=k){
        for(int j = c;j<=n;j+=k)a[i][j] = 'X';
        for(int j = c;j>=1;j-=k)a[i][j] = 'X';
    }
    for(int i = r;i<=n;i+=k){
        for(int j = c;j<=n;j+=k)a[i][j] = 'X';
        for(int j = c;j>=1;j-=k)a[i][j] = 'X';
    }
    vector<int>rows,cols;
    for(int i = 1;i<=n;++i){
        if(abs(r-i)%k!=0)rows.pb(i);
        if(abs(c-i)%k!=0)cols.pb(i);
    }
    for(int i = 0;i<rows.size();++i){
        int r = rows[i], c = cols[i];
        for(int j = c;j>=1;j-=k){
            a[r][j] = 'X';
        }
        for(int j = c;j<=n;j+=k){
            a[r][j] = 'X';
        }
        for(int i = r;i>=1;i-=k){
            a[i][c] = 'X';
        }
        for(int i = r;i<=n;i+=k){
            a[i][c] = 'X';
        }
    }

    for(int i =1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            cout << a[i][j];
        }
        cout << endl;
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