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

int n,x;
vector<int>a,pref,pref2;
int sum(int a, int n){
    return (n*(2*a+(n-1)))/2;
}
int give(int i, int y, int take){
    // sum if we start from y in the ith index
    int x = take;
    if((a[i]-y+1)>=x)return sum(y,x);
    int res = sum(y,a[i]-y+1);
    int rem = x-(a[i]-y+1);
    // fidn the first value in pref <= rem
    int val = upper_bound(all(pref),rem+pref[i])-pref.begin()-1;
    res+=pref2[val]-pref2[i];
    rem-=(pref[val]-pref[i]);
    if(val < n && rem){
        res+=sum(1,rem);
        return res;
    }
    val = upper_bound(all(pref),rem)-pref.begin()-1;
    res+=pref2[val];
    rem-=pref[val];
    if(rem){
        res+=sum(1,rem);
    }
    return res;
}
void solve()
{
    cin >> n >> x;
    a.resize(n+1);
    pref.resize(n+1);
    pref2.resize(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=n;++i)pref[i] = pref[i-1]+a[i],pref2[i]=pref2[i-1]+sum(1,a[i]);

    int res = 0;
    for(int i = 1;i<=n;++i){
        int c = 0;
        if(pref[i]>=x){
            // first element >= pref[i]-x
            int val = lower_bound(all(pref),pref[i]-x)-pref.begin();
            int rem = x-(pref[i]-pref[val]);
            int y = a[val]-rem+1;
            if(y>a[val])y = 1, val++;
            c = give(val,y,x);
        }else{
            c = pref2[i];
            int rem = x-pref[i];
            int val = lower_bound(all(pref),pref[n]-rem+1)-pref.begin();
            rem = rem-(pref[n]-pref[val]);
            int y = a[val]-rem+1;
            if(y>a[val])y = 1, val++;
            c += give(val,y,rem);
        }
        res = max(res, c);
        // int l = 1, r = a[i];
        // while(l+2 < r){
        //     int m1 = (l+(r-l)/3);
        //     int m2 = r-((r-l)/3);
        //     if(give(i,m1)>give(i,m2))r = m2;
        //     else l = m2;
        // }
        // for(int j = l;j<=r;++j)res = max(res, give(i,j));
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