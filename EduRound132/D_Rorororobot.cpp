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

struct segtree{
    int sz = 1;
    vector<int>mx;
    void init(int n){
        while(sz < n)sz*=2;
        mx.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx - lx == 1){
            // leaf
            mx[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        mx[x] = max(mx[2*x+1], mx[2*x+2]);
    }

    void set(int i, int v){
        set(0, 0, sz, i, v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx>=r)return 0ll;
        if(rx <= r && lx>=l)return mx[x];
        int m = (lx+rx)/2;
        int left = sol(2*x+1, lx, m, l, r);
        int right = sol(2*x+2, m, rx, l, r);
        return max(left, right);
    }

    int sol(int l, int r){
        return sol(0, 0, sz, l, r);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>a(m);
    for(int i = 0;i<m;++i)cin >> a[i];
    int q;
    cin >> q;
    segtree st;
    st.init(m);

    for(int i = 0;i<m;++i)st.set(i, a[i]);
    while(q--){
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        if(x1 > x2){
            swap(x1, x2);
            swap(y1, y2);
        }
        // x1 < x2
        // go to the highest point possible in this column
        int highestx = x1 + k*((n-x1)/k);
        int max_height_in_range = st.sol(min(y1, y2)-1, max(y1, y2));
        if(max_height_in_range < highestx && (x2-x1)%k == 0 && abs(y2 - y1)%k == 0)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}