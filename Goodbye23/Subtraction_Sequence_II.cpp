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

const int N = 2e5+5;
struct segtree{
    int sz = 1;
    vector<int>seg,left,right;
    int node = 0;
    void init(int n){
        sz = n;
        seg.pb(0);
        left.pb(-1);
        right.pb(-1);
    }
    int get_next(){
        node++;
        left.pb(-1);
        right.pb(-1);
        seg.pb(0);
        return node;
    }
    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        if(left[x]==-1)left[x] = get_next();
        if(right[x]==-1)right[x] = get_next();
        if(i < m)set(left[x], lx, m, i, v);
        else set(right[x], m, rx, i, v);
        seg[x] = seg[left[x]]+seg[right[x]];
    }
 
    void set(int i, int v){
        set(0,0,sz,i,v);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(lx >= l && rx <= r)return seg[x];
        if(lx >= r || rx <= l)return 0ll;
        int m = (lx+rx)/2;
        if(left[x]==-1)left[x] = get_next();
        if(right[x]==-1)right[x] = get_next();
        return sol(left[x], lx, m,l,r)+sol(right[x],m,rx,l,r);
    }
 
    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

vector<int>pp(N);
int mod = 1e9+7;
int ma(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}

int mm(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}
int ms(int a, int b){
    return ((((a%mod)-(b%mod))%mod)+mod)%mod;
}
void pre(){
    pp[0] = 1;
    for(int i = 1;i<N;++i)pp[i] = mm(pp[i-1],2);
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1); int sum = 0;
    for(int i =1 ;i<=n;++i)cin >> a[i], sum+=a[i];
    int res = mm(pp[n-1],sum);
    // find count of values > a[i] in the suffix
    set<int>kk(a.begin()+1, a.end());
    int g = 1;
    map<int,int>coord;
    for(auto x : kk)coord[x] = g++;
    segtree st,st2;
    st.init(n+1);
    st2.init(n+1);
    for(int i = 1;i<=n;++i)st.set(coord[a[i]],1),st2.set(coord[a[i]],a[i]);

    for(int i = 1;i<n;++i){
        st.set(coord[a[i]],-1);
        sum-=a[i];
        st2.set(coord[a[i]],-a[i]);
        int greater = st.sol(coord[a[i]]+1,n+1);
        int rem = (n-i)-greater;
        int sm = sum - st2.sol(coord[a[i]]+1,n+1);

        res = ms(res,mm(a[i]*greater,pp[i-1]));
        res = ms(res,mm(sm,pp[i-1]));

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
    pre();
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve(); 
    }
}