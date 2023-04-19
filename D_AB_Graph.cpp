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



void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>>a(n+1, vector<char>(n+1));
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j)cin >> a[i][j];
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            if(i==j)continue;
            if(m==1){
                cout << "YES" << endl;
                cout << i << ' ' << j << endl;
                return;
            }
            if(a[i][j]==a[j][i]){
                cout << "YES" << endl;
                for(int k = 1;k<=m+1;++k){
                    if(k%2)cout << i << ' ';
                    else cout << j << ' ';
                }
                cout << endl;
                return;
            }
        }
    }
    // edge from (u,v) != (v,u) edge for every pair (u,v)
    if(m%2){
        cout << "YES" << endl;
        for(int i = 1;i<=m+1;++i){
            if(i%2)cout<< 1 << ' ';
            else cout << 2 << ' ';
        }
        cout << endl;
        return;
    }
    if(n==2){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int u,v,o;
    for(int i = 1;i<=3;++i){
        for(int j = 1;j <= 3 ;++j){
            if(i==j)continue;
            set<int>c = {1,2,3};
            c.erase(i);
            c.erase(j);
            int other = *c.begin();
            if(a[other][i]==a[i][j]){
                o = other;
                u = i;
                v = j;
            }
        }
    }

    if((m/2)%2){
        for(int i =1 ;i<=m/2;++i){
            if(i%2)cout << o << ' ' ;
            else cout << u << ' ';
        }
        for(int i = 1;i<=(m/2)+1;++i){
            if(i%2)cout << u << ' ';
            else cout << v << ' ';
        }
        cout << endl;
        return;
    }
    swap(o,u);
    vector<int>pattern = {v,o,u,o};
    cout << o << ' ';
    for(int i = 1;i<=(m/4);++i){
        for(auto x : pattern)cout << x << ' ';
    }
    cout << endl;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}