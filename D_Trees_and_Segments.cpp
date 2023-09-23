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


struct line{
    int m,c=-1e18;
    int f(int x){
        return m * x + c;
    }
};
struct lichao{
    int sz = 1;
    vector<line>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }

    void set(int x, int lx, int rx, line l){
        int m = (lx+rx)/2;
        bool le = l.f(lx) > seg[x].f(lx);
        bool mi = l.f(m) > seg[x].f(m);
        if(mi)swap(l,seg[x]);
        if(rx-lx > 1){
            if(le!=mi){
                set(2*x+1,lx,m,l);
            }else set(2*x+2,m,rx,l);
        }
    }

    void set(int m, int c){
        line l = {m,c};
        set(0,0,sz,l);
    }

    int sol(int x, int lx, int rx, int X){
        if(rx-lx==1)return seg[x].f(X);
        int m = (lx+rx)/2;
        if(X < m)return max(seg[x].f(X), sol(2*x+1,lx,m,X));
        else return max(seg[x].f(X), sol(2*x+2,m,rx,X));
    }

    int sol(int x){
        return sol(0,0,sz,x);
    }
};

void solve()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int>ones, zeroes;
    s = "0"+s;ones.pb(0);zeroes.pb(0);
    for(int i= 1;i<=n;++i){
        if(s[i]=='1')ones.pb(i);
        else zeroes.pb(i);  
    }
    lichao st;
    st.init(n+1);
    vector<vector<int>>suff(n+2, vector<int>(n+1)); // suff[i][j] denotes the maximum contiguous black sequence in suffix starting from i if you make j changes
    vector<vector<int>>pref(n+1, vector<int>(n+1));
    int mx2 = 0;
    int cnt = 0;
    int curr = zeroes.size();
    vector<int>mxxx(k+1);
    for(int i = n;i>=1;--i){
        if(s[i] == '0')curr--;
        if(s[i]=='1')cnt++;
        else cnt = 0;
        mx2 = max(mx2, cnt);
        suff[i][0] = mx2;
        if(curr == zeroes.size())continue;
        for(int j = 1;j<=k;++j){
            int till = n;
            if(curr+j < zeroes.size())till = zeroes[curr+j]-1;
            mxxx[j] = max(mxxx[j],till-i+1);
            suff[i][j] = mxxx[j];
        }
    }
    cnt = 0;
    mx2  = 0;
    curr = 0;
    vector<int>mxx(k+1);
    for(int i = 1;i<=n;++i){
        if(s[i]=='0')curr++;
        if(s[i]=='1')cnt++;
        else cnt = 0;
        mx2 = max(mx2, cnt);
        pref[i][0] = mx2;
        if(curr==0)continue;
        for(int j = 1;j<=k;++j){
            int till = 1;
            if(curr - j > 0)till = zeroes[curr-j]+1;
            mxx[j] = max(mxx[j], i-till+1);
            pref[i][j] = mxx[j];
        }
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=k;++j)pref[i][j] = max(pref[i][j], pref[i][j-1]), suff[i][j] = max(suff[i][j], suff[i][j-1]);
    }
    curr = 0;
    cnt = 0;
    vector<vector<int>>pos(n+1, vector<int>(n+1));
    for(int i = 1;i<=n;++i){
        if(s[i]=='1')curr++;
        if(s[i]=='0')cnt++;
        else cnt = 0;
        int get0 = cnt, get1 = max(suff[i+1][k],pref[i-cnt][k]);
        pos[get0][get1] = 1;

        if(s[i]!='1')continue;
        for(int j = 1;j<=k;++j){
            int till = n;
            if(curr+j < ones.size())till = ones[curr+j]-1;
            int get0 = till - ones[curr-1];
            int get1 =  max(pref[ones[curr-1]][k-j], suff[till+1][k-j]);
            pos[get0][get1] = 1;
        }
    }
    for(int i = 0;i<=n;++i){
        for(int j = n;j>=0;--j){
            if(pos[i][j])st.set(i,j);
            if(pos[i][j])break;
        }
    }
    for(int j = 1;j<=n;++j){
        cout << st.sol(j) << ' ';
    }
    cout << endl;
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