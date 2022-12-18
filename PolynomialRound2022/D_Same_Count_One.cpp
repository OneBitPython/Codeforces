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
    cin >> n>> m;
    vector<pair<int,vector<int>>>a(n+1);
    for(int i = 1;i<=n;++i){
        a[i].first = i;
        vector<int>c(m+1);
        for(int j = 1;j<=m;++j)cin >> c[j];
        a[i].second = c;
    }
    sort(a.begin()+1, a.end(), [&](auto one, auto two){
        return count(all(one.second),1) > count(all(two.second),1);
    });
    int c = 0;
    for(auto x : a){
        for(auto y : x.second)c+=y;
    }
    if(c%n != 0){
        cout << -1 << endl;
        return;
    }
    int req = c/n;
    int l = 1, r = n;
    vector<vector<int>>res;
    while(l < r){
        int c1 = count(all(a[l].second),1), c2 = count(all(a[r].second),1);
        if(c1==req)l++;
        if(c2==req)r--;
        if(c1 != req && c2 != req){
            int give = min(req-c2,c1-req);
            for(int j = 1;j<=m;++j){
                if(give == 0)break;
                if(a[l].second[j] == 1 && a[r].second[j]==0){
                    swap(a[l].second[j],a[r].second[j]);
                    res.pb({a[l].first, a[r].first,j});
                    give--;
                }
            }
        }
    }
    cout << res.size() << endl;
    for(auto x : res)cout << x[0] << ' ' << x[1] << ' ' << x[2]  << ' ';
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