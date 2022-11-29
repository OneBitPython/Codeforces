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


map<int,int>cnt,pref,took;

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    cnt.clear();
    pref.clear();
    took.clear();
    for(int i = 0;i<n;++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int res = 0;
    set<int>b(all(a));
    int prev = 0;
    for(int i : b){
        pref[i] = pref[prev] + cnt[i];
        res+=(cnt[i]/2);
        prev = i;
    }
    // res currently stores the cost if everything is disconnected and put in pairs
    sort(all(a));

    int cost = 0;

    int v = lower_bound(all(a),a.back())-a.begin() - 1;
    if(v < 0)v = 0;
    else v = a[v];
    cost+=(pref[v]);


    res = max(res, cost+((cnt[a[n-1]]-1)/2));
    took[a[n-1]]++;
    int taken = 0;
    for(int i = n-2;i>=0;--i){
        if(a[i]!=a[i+1]){
            taken+=cnt[a[i+1]];
        }
        int v = lower_bound(all(a),a[i])-a.begin() - 1;
        if(v < 0)v = 0;
        else v = a[v];

        cost+=pref[v];
        cost-=taken;
        took[a[i]]++;
        int extra = (cnt[a[i]]-took[a[i]])/2;
        res = max(res, cost);
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
    // #endif

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}