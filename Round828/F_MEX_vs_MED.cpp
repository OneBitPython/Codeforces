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

int sum(int a, int n){
    return (n*((2*a)+(n-1)))/2;
}

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i =1;i<=n;++i)cin >> a[i];
    vector<int>p(n+1);
    for(int i =1;i<=n;++i)p[a[i]] = i;
    vector<int>pmin(n),pmax(n);
    pmin[0] = p[0];
    pmax[0] = p[0];
    for(int i = 1;i<n;++i){
        pmin[i] = min(pmin[i-1],p[i]);
        pmax[i] = max(pmax[i-1],p[i]);
    }
    int res = 0;
    for(int x = 1;x<n;++x){
        // let mex be == x
        int mx = pmax[x-1];
        int mn = pmin[x-1];
        int pos_next = p[x];
        if(pos_next >= mn && pos_next <= mx){
            continue;
        }
        
        // max subarray size which has mex = x and has mex > med has size x * 2
        int max_sz = x*2;
        if((mx-mn+1)>max_sz)continue;
        if(pos_next < mn){
            int mng = mx-mn+1;
            int mxg = min(max_sz,n-mn+1);
            int sz = mxg-mng+1;
            int time = max_sz-mxg+1;
            time = min(time, mn-pos_next);
            res+=(time*sz);
            mn-=time;
            if(mn <= 0)continue;
            int end = max(pos_next,mx-max_sz);
            int rem = mn-end;
            if(rem<=0)continue;
            sz--;
            int st = sz-rem+1;
            res+=sum(st,rem);
        }else{
            int mng = mx-mn+1;
            int mxg = min(max_sz,pos_next-mn);
            int sz = mxg-mng+1;
            int time = min(max_sz-mxg+1,mn);
            res+=(time*sz);
            mn-=time;
            if(mn <= 0)continue;
            int end = max(1ll,mx-max_sz+1);
            int rem = mn-end+1;
            if(rem<=0)continue;
            sz--;
            int st = sz-rem+1;
            res+=sum(st,rem);
        }
        dbg(res);
    }
    cout << res+1 << endl;
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