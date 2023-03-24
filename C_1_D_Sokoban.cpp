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

int bet(int l, int r, vector<int>&a){
    // binary search on number of values in range [l,r] in a
    return a.end()-lower_bound(all(a),l) - (a.end()-upper_bound(all(a),r));
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int>a(n+1), b(m+1);
    map<int,int>pres;
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=m;++i)cin >> b[i],pres[b[i]] = 1;
    int x = -1;
    for(int i = 1;i<=n;++i){
        if(a[i] >= 0){
            x = a[i];
            break;
        }
    }
    vector<int>match(n+2);
    for(int i = n;i>=1;--i){
        match[i] = match[i+1];
        if(pres[a[i]])match[i]++;
    }
    int ans = 0;
    if(x!=-1){
        for(int i = 1;i<=m;++i){
            if(b[i] >= x){
                // assume x moves till b[i], binary search on the position that the chain of boxes ends
                int l = b[i], r = 2e9;
                int res = l;
                while(l <= r){
                    int m = (l+r)/2;
                    // find number of values in a that are >= x and <= m
                    int cnt = bet(x,m,a)-1;
                    if(b[i]+cnt < m)r = m-1;
                    else if(b[i]+cnt==m){
                        res = m;
                        break;
                    }else l = m+1;
                }
                // find number of b[i] between [b[i],res]
                int get = bet(b[i],res,b);
                int pos = upper_bound(all(a),res)-a.begin();
                get+=match[pos];
                ans = max(ans, get);
            }
        }
    }
    int mx = 0;
    // do the same for -ve values
    vector<int>c={0},d={0};
    for(int i = 1;i<=n;++i){
        if(a[i]<0)c.pb(abs(a[i]));
    }
    for(int i = 1;i<=m;++i){
        if(b[i]<0)d.pb(abs(b[i]));
    }
    if(c.size()>1)reverse(c.begin()+1, c.end());
    if(d.size()>1)reverse(d.begin()+1, d.end());
    int k = c.size()-1;
    match = vector<int>(k+2);
    pres.clear();
    for(int i = 1;i<(int)(d.size());++i)pres[d[i]]++;
    for(int i = k;i>=1;--i){
        match[i] = match[i+1];
        if(pres[c[i]])match[i]++;
    }
    if(c.size()>1 && d.size()>1){
        x = c[1];
        for(int i = 1;i<(int)(d.size());++i){
            if(d[i] >= x){
                // assume x moves till d[i], binary search on the position that the chain of boxes ends
                int l = d[i], r = 2e9;
                int res = l;
                while(l <= r){
                    int m = (l+r)/2;
                    // find number of values in c that are >= x and <= m
                    int cnt = bet(x,m,c)-1;
                    if(d[i]+cnt < m)r = m-1;
                    else if(d[i]+cnt==m){
                        res = m;
                        break;
                    }else l = m+1;
                }
                // find number of d[i] between [b[i],res]
                int get = bet(d[i],res,d);
                int pos = upper_bound(all(c),res)-c.begin();
                get+=match[pos];
                mx = max(mx, get);
            }
        }
    }
    cout << ans+mx << endl;
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