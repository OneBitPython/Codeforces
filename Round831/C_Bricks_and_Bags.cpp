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

int f(int a,int b, int c){
    return abs(b-a)+abs(c-a);

}
int go(vector<int>&a, int b, int c){
    int n = a.size();
    vector<int>res(5,1e18);
    vector<int>spec;
    // dbg(b,c);
    for(int i = 0;i<n;++i){
        if(i==b || i == c)continue;
        if(a[i] == a[b] || a[i] == a[c])continue;
        vector<int>choose = {a[i],a[b],a[c]};
        res[0] = min(res[0],f(a[i],a[b],a[c]));
        res[1] = min(res[1], f(a[i],a[c],a[b]));
        res[2] = min(res[2], f(a[b],a[i],a[c]));
        res[3] = min(res[3], f(a[b],a[c],a[i]));
        res[4] = min(res[4],f(a[c],a[b],a[i]));
    }
    int mn = *max_element(all(res));
    return mn;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >>u;
    vector<pair<int,int>>b;
    for(int i = 0;i<n;++i)b.pb({a[i],i});
    set<int>s(all(a));
    if(s.size() == 1){
        cout << 0 << endl;
        return;
    }else if(s.size() == 2){
        int u = *s.begin(), v = *(--s.end());
        cout<< abs(u-v)*2 << endl;
        return;
    }
    sort(all(b));
    // select two mins and check others, or you select two max and checkothers, or you select min and max and check otehrs
    cout << max({go(a, b[0].second, b[1].second), go(a, b[0].second, b.back().second), go(a, b.back().second, b[n - 2].second)}) << endl;
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