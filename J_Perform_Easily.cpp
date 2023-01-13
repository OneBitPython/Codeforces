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
    int m = 6;
    vector<int>a(m+1);
    for(int i = 1;i<=m;++i)cin >> a[i];
    int n;
    cin >> n;
    vector<int>b(n+1);
    for(int i = 1;i<=n;++i)cin >> b[i];

    vector<pair<int,int>>c;
    for(int i = 1;i<=m;++i){
        for(int j = 1;j<=n;++j)c.pb({b[j]-a[i],j});
    }
    sort(all(c));
    set<int>to_add;
    for(int i = 1;i<=n;++i)to_add.insert(i);
    int r = 0;
    int k = c.size();
    int res = c.back().first-c.front().first;
    map<int,int>cnt;
    for(int i = 0;i<k;++i){
        while(!to_add.empty() && r < k){
            to_add.erase(c[r].second);
            cnt[c[r].second]++;
            r++;
        }
        
        if(!to_add.empty())break;
        res = min(res, c[r-1].first-c[i].first);
        cnt[c[i].second]--;
        if(cnt[c[i].second]==0)to_add.insert(c[i].second);
    }
    cout << res << endl;
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