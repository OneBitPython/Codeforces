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


vector<int>query(int l, int r){
    cout << "? " << l << ' ' << r << endl;
    vector<int>res;
    for(int i = 1;i<=(r-l+1);++i){
        int v;
        cin >> v;
        res.pb(v);
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    int l = 0, r =n;
    while(l+1 < r){
        int m = (l+r)/2;
        vector<int> res = query(l+1, m);
        if((m-(l+1)) == 0){
            if(res[0] == m){
                cout << "! " <<  m << endl;
                return;
            }
        }
        int cnt = 0;
        for(int i = 1;i<=(int)(res.size());++i){
            if(res[i-1] >= (l+1) && res[i-1] <= m){
                cnt++;
            }
        }
        if(cnt%2)r = m;
        else l =m;
    }
    cout << "! " << r << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}