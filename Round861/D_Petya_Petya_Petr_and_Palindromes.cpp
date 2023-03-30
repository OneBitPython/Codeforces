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

int n,k;
int inv(int i, int j){
    int st = i-j+1, e = st+k-1;
    return e-j+1;
}

void solve()
{
    cin >> n >> k;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    int mx = *max_element(all(a));
    vector<vector<int>>idx(mx+1),eve(mx+1),odd(mx+1);
    for(int i = 1;i<=n;++i)idx[a[i]].pb(i);
    for(int i = 1;i<=mx;++i){
        int m = idx[i].size();
        if(m==0)continue;
        eve[i].pb((idx[i][0]%2) == 0);
        for(int j = 1;j<m;++j)eve[i].pb(eve[i].back()+((idx[i][j]%2)==0));
        odd[i].pb((idx[i][0]%2));
        for(int j = 1;j<m;++j)odd[i].pb(odd[i].back()+((idx[i][j]%2)));
    }
    int res = 0;
    for(int i = 1;i<=n;++i){
        int val = (n-i-k);
        // -x <= val
        // x <= min(i,k/2)
        val = min(val,-1ll);
        // x >= val
        // x <= min(i,k/2)
        int mn = abs(val), mx = min(i,k/2);
        if(mx < mn)break;
        int l = inv(i,mn), r = inv(i,mx);
        swap(l,r);
        int get = (r-l+2)/2;
        int beg = lower_bound(all(idx[a[i]]),l)-idx[a[i]].begin(), e = upper_bound(all(idx[a[i]]), r)-idx[a[i]].begin()-1;
        if(beg >= idx[a[i]].size()){
            res+=get;
            continue;
        }
        int cnt = 0;
        if((l%2)==0){
            cnt+=(eve[a[i]][e]);
            if(beg>0)cnt-=eve[a[i]][beg-1];
        }else{
            cnt+=(odd[a[i]][e]);
            if(beg>0)cnt-=odd[a[i]][beg-1];
        }
        res+=(get-cnt);
    }
    cout << res;
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