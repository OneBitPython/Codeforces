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


const int mxc = 1e6+1;
int mx[mxc+1];
pair<int,int>idx[mxc+1];
void solve()
{
    int n,c;
    cin >> n >> c;
    vector<pair<int,int>>a;
    a.pb({0,0});
    for(int i = 0;i<mxc;++i)mx[i] = -1;
    for(int i = 1;i<=n;++i){
        int c,d,h;
        cin >> c >> d >> h;
        int k = d*h;
        if(k > mx[c]){
            mx[c] = k;
            idx[c] = {c,k};
        }
    }
    for(int i = mxc-1;i>=1;--i){
        if(mx[i]==-1)continue;
        for(int j = 2*i;j<=c;j+=i){
            int k = (j/idx[i].first)*idx[i].second;
            if(k > mx[j]){
                mx[j] = k;
                idx[j] = {j,k};
            }
        }
    }
    for(int i = 1;i<=c;++i){
        if(mx[i]!=-1)a.pb(idx[i]);
    }

    sort(a.begin()+1,a.end(), [&](auto one, auto two){
        return one.second > two.second;
    });
    int m;
    cin >> m;
    vector<pair<int,int>>queries;
    vector<int>res(m+1);
    for(int i =1 ;i<=m;++i){
        int d,h;
        cin >> d >> h;
        queries.pb({d*h, i});
    }
    sort(all(queries));
    reverse(all(queries));
    int p = 1, ans = 1e9;
    int get = 0;
    for(auto x : queries){
        while(p < (int)(a.size()) && a[p].second > x.first){
            get = 1;
            ans = min(ans, a[p].first);
            p++;
        }
        if(get)res[x.second] = ans;
        else res[x.second] = -1;
    }
    for(int i = 1;i<=m;++i)cout << res[i] << ' ';
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