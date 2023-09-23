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

int val(char x){
    return (1ll<<(x-'a'));
}

string conv(vector<vector<char>>&a){
    int i = 1, j = 1;
    string s;
    s+=a[i][j];
    s+=a[i][j+1];
    s+=a[i+1][j];
    s+=a[i+1][j+1];
    return s;
}

void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<char>>a(n+1,vector<char>(m+1)),b(3,vector<char>(3));
    for(int  i =1 ;i<=n;++i){
        for(int j= 1;j<=m;++j)cin >> a[i][j];
    }
    for(int i= 1;i<=2;++i){
        for(int j = 1;j<=2;++j)cin >> b[i][j];
    }
    map<string,int>freq;
    for(int i= 1;i<=n-1;++i){
        for(int j = 1;j<=(m-1);++j){
            string s;
            s+=a[i][j];
            s+=a[i][j+1];
            s+=a[i+1][j];
            s+=a[i+1][j+1];
            freq[s]++;
        }
    }

    cout << freq[conv(b)] << endl;
    vector<vector<pair<int,int>>>ord = {
        {{-1,-1},{-1,0},{0,-1},{0,0}},
        {{-1,0},{-1,1},{0,0},{0,1}},
        {{0,-1},{0,0},{1,-1},{1,0}},
        {{0,0},{0,1},{1,0},{1,1}}
    };
    while(q--){
        int t;cin >> t;
        int i,j;
        char x;
        cin >> i >> j >> x;
        if(t==1){
            
            for(auto w : ord){
                string s;
                bool ok = 1;
                for(auto &[u,v] : w){
                    if((i+u)<=n && (i+u)>=1 && (j+v)<=m && (j+v)>=1)s+=(a[i+u][j+v]);
                    else ok = 0;
                }
                if(ok)freq[s]--;
            }
            a[i][j] = x;
            for(auto w : ord){
                string s;
                bool ok = 1;
                for(auto &[u,v] : w){
                    if((i+u)<=n && (i+u)>=1 && (j+v)<=m && (j+v)>=1)s+=(a[i+u][j+v]);
                    else ok = 0;
                }
                if(ok)freq[s]++;
            }
        }else{
            b[i][j] = x;
        }
        cout << freq[conv(b)] << endl;
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}