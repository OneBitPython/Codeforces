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
    int n,k;
    cin >> n >> k;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin>> a[i];
    // dp stores set of {min(a[u],a[v]), u} where u and v are adjacent values
    set<pair<int,int>>dp;
    vector<pair<int,int>>b;
    b.pb({0,0});
    for(int i= 1;i<=n;++i)b.pb({a[i], i});
    sort(b.begin()+1, b.end());
    for(int i = 1;i<=k-1;++i)a[b[i].second] = 1e9;

    int res = 0;
    for(int i = 1;i<n;++i)dp.insert({min(a[i],a[i+1]), i});

    multiset<int>st;
    for(int i = 1;i<=n;++i){
        if(a[i]==1e9)continue;
        st.insert(a[i]);
    }

    for(int i = 1;i<=n;++i){
        if(a[i]==1e9)continue;
        st.erase(st.find(a[i]));
        if(st.empty()){
            cout << (int)(1e9) << endl;
            return;
        }
        int mn = *st.begin();
        
        if(i < n)dp.erase({min(a[i],a[i+1]), i});
        if(i > 1)dp.erase({min(a[i-1],a[i]), i-1});

        if(i < n)dp.insert({a[i+1], i});
        if(i > 1)dp.insert({a[i-1],i-1});
        
        int val = (*--dp.end()).first;
        res = max(res, min(val,mn*2));

        if(i < n)dp.erase({a[i+1], i});
        if(i > 1)dp.erase({a[i-1],i-1});


        if(i < n)dp.insert({min(a[i],a[i+1]), i});
        if(i > 1)dp.insert({min(a[i-1],a[i]), i-1});
        st.insert(a[i]);
    }

    cout << min((int)(1e9),res) << endl;
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