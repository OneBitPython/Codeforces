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

bool fine(int i, int j, vector<vector<char>>&a,char x){
    set<char>b={a[i-1][j],a[i+1][j],a[i][j-1],a[i][j+1]};
    if(b.size() > 1)return 0;
    if(*b.begin() == x)return 0;
    return 1;
}

void solve()
{
    int n,m,k;cin >> n >> m >> k;
    int fr = 0;
    k++;
    vector<vector<vector<char>>>a(k+1, vector<vector<char>>(n+1, vector<char>(m+1)));
    for(int i = 1;i<=k;++i){
        for(int j = 1;j<=n;++j){
            for(int l = 1;l<=m;++l)cin >> a[i][j][l];
        }
    }
    for(int i = 1;i<=k;++i){
        // check if this is your starting
        // if this is the starting point you can make transitions to all other pictures
        bool best = 1;
        for(int j = 1;j<=k;++j){
            if(i==j)continue;
            // make sure you can transition from i->j
            bool ok = 1;
            for(int l = 2;l<n;++l){
                for(int p = 2;p<m;++p){
                    if(a[i][l][p] != a[j][l][p]){
                        ok&=fine(l,p,a[i],a[i][l][p]);
                    }
                }
            }
            best&=ok;
        }
        if(best)fr = i;
    }
    cout << fr << endl;
    vector<vector<int>>res;
    vector<int>took(k+1);
    took[fr] = 1;
    for(int i = 1;i<k;++i){
        vector<pair<int,int>>pos;
        for(int j = 1;j<=k;++j){
            if(took[j])continue;
            int t = 0;
            bool ok = 1;
            for(int l= 2;l<n;++l){
                for(int p = 2;p<m;++p){
                    
                    if(a[fr][l][p]!=a[j][l][p])ok&=fine(l,p,a[fr],a[fr][l][p]);
                    if(a[fr][l][p]!=a[j][l][p] && ok)t++;
                }
            }
            if(ok)pos.pb({t,j});
        }
        sort(all(pos));
        if(pos.empty())break;
        int j = pos[0].second;
        for(int l= 2;l<n;++l){
            for(int p = 2;p<m;++p){
                if(a[fr][l][p]!=a[j][l][p])res.pb({1,l,p});
            }
        }
        fr = j;
        took[fr] = 1;
        res.pb({2,fr});
    }
    cout << res.size() << endl;
    for(auto x : res){
        for(auto y : x)cout << y << ' ';
        cout << endl;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}