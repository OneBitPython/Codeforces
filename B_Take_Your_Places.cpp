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
    vector<int>sums;
    void init(int n){
        while(sz < n)sz*=2;
        sums.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx - lx == 1){
            sums[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        sums[x] =sums[2*x+1] + sums[2*x+2];
    }

    void set(int i, int v){
        set(0, 0, sz, i, v);
    }

    int sum(int x, int lx, int rx, int l, int r){
        if(lx>=r || rx<=l)return 0ll;
        if(lx>=l && rx<=r)return sums[x];
        int m = (lx+rx)/2;
        return sum(2*x+1, lx, m, l, r) + sum(2*x+2, m, rx, l, r);
    }

    int sum(int l, int r){
        return sum(0, 0, sz, l, r);
    }
};

int cost(vector<int>&res){
    int n = res.size();
    segtree st;
    st.init(n+2);
    st.set(res[0], 1);
    int s = 0;

    for(int i = 1;i<n;++i){
        s+=(st.sum(res[i]+1, n+1));
        st.set(res[i], 1);
    }
    return s;
}

void solve()
{
    int n;
    cin >> n;
    vector<int>e, o;
    for(int i = 0;i<n;++i){
        int v;
        cin >> v;
        if(v&1)o.pb(i);
        else e.pb(i);
    }
    if(abs((int)(e.size()-o.size()))>=2){
        cout << -1 << endl;
        return;
    }
    vector<int>res;
    bool m = 1;
    int ans = 1e18;
    if(e.size() > o.size())m = 0;
    else if(e.size() == o.size()){
        int pos1 = 0, pos2 = 0;
        for(int i = 0;i<n;++i){
            if(!m){
                res.pb(e[pos1]);
                pos1++;
            }else{
                res.pb(o[pos2]);
                pos2++;
            }
            m =!m;
        }
        ans = min(ans, cost(res));
        res.clear();
        m = 0;
    }
    // m = 0, if you have to start with even
    int pos1 = 0, pos2 = 0;
    for(int i = 0;i<n;++i){
        if(!m){
            res.pb(e[pos1]);
            pos1++;
        }else{
            res.pb(o[pos2]);
            pos2++;
        }
        m =!m;
    }
    ans = min(ans, cost(res));
    cout << ans << endl;
    // count inversions in A
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