#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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

int give_sum(int l, int r, vector<int>&a){
    int mxr = 0, mnr = 1e18;
    int mx = 0, mn = 1e18;
    if(r < l)swap(l,r);
    if(l == 0 && r == (int)(a.size())-1)return 0ll;
    for(int i = l;i<=r;++i){
        mxr = max(mxr, a[i]);
        mnr = min(mnr, a[i]);
    }
    for(int i = l-1;i>=0;--i){
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    for(int i = r+1;i<(int)(a.size());++i){
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    return (mxr-mnr) + (mx-mn);
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    vector<int>b;
    for(int i = 0;i<n;++i){
        cin >> a[i].first;
        b.pb(a[i].first);
        a[i].second = i;
    }

    sort(all(a));
    int min_ = a[0].second, second_min = a[1].second;
    int max_ = a.back().second, second_max = a[n-2].second;
    // dbg(min_, second_min, max_, second_max,give_sum(second_min, second_max, b));
    cout << max({*max_element(all(b))-*min_element(all(b)), give_sum(min_, second_min, b), give_sum(max_, second_max, b), give_sum(min_, max_,b), give_sum(min_, second_max,b), give_sum(second_min, max_, b), give_sum(second_min, second_max, b)}) << endl; 
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