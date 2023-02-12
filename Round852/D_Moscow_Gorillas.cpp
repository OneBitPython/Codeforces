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

int inrange(int l, int r, int x){
    if(x >= l && x <= r)return 1ll;
    return 0ll;
}

int give(int l, int r){
    if(l > r)return 0ll;
    int sz = (r-l+1);
    return (sz*(sz+1))/2;
}

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1), b(n+1);
    vector<int>pos1(n+1), pos2(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=n;++i)cin >> b[i];
    for(int i = 1;i<=n;++i){
        pos1[a[i]] = i;
        pos2[b[i]] = i;
    }
    // find the answer when mex = 1
    int l = 1,r=min(pos1[1]-1,pos2[1]-1);
    int res = give(l,r)+1+give(max(pos1[1]+1,pos2[1]+1),n)+give(pos1[1]+1,pos2[1]-1)+give(pos2[1]+1,pos1[1]-1);

    int mn1 = 1e18, mx1 = 0, mn2 = 1e18, mx2 = 0;
    for(int i = 1;i<n;++i){
        mn1 = min(mn1, pos1[i]);
        mx1 = max(mx1, pos1[i]);
        mn2 = min(mn2, pos2[i]);
        mx2 = max(mx2, pos2[i]);
        int nxt1 = pos1[i+1], nxt2 = pos2[i+1];
        int incll = min(mn1, mn2), inclr = max(mx1, mx2);
        if(inrange(incll,inclr,nxt1) || inrange(incll,inclr,nxt2))continue;
        int mxextright = 1ll;
        if(nxt1 < incll)mxextright = max(mxextright,nxt1+1);
        if(nxt2 < incll)mxextright = max(mxextright,nxt2+1);

        int mxextleft = n;
        if(nxt1 > inclr)mxextleft = min(mxextleft, nxt1-1);
        if(nxt2 > inclr)mxextleft = min(mxextleft,nxt2-1);
        res+=(incll-mxextright+1)*(mxextleft-inclr+1);
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