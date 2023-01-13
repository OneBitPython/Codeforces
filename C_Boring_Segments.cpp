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


int n,m;
vector<vector<int>>edges;
struct segtree{
    int sz = 1;
    vector<int>seg,lazy;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    void rangeupdate(int x, int lx, int rx, int l, int r, int y){
        if(lazy[x]!=0){
            seg[x]+=lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }

        if(rx <= l || lx >= r)return;
        if(lx >= l && rx <= r){
            seg[x]+=y;
            if(rx-lx > 1){
                lazy[2*x+1]+=y;
                lazy[2*x+2]+=y;
            }
            return;
        }
        int m = (lx+rx)/2;
        rangeupdate(2*x+1, lx, m, l,r, y);
        rangeupdate(2*x+2, m, rx, l,r, y);
        seg[x] = min(seg[2*x+1],seg[2*x+2]);
    }

    void rangeupdate(int l, int r, int y){
        rangeupdate(0,0,sz,l,r,y);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]!=0){
            seg[x]+=lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }
        if(rx <= l || lx >= r)return 1e18;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return min(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

void solve()
{
    cin >> n >> m;
    for(int i = 0;i<n;++i){
        int l,r,w;
        cin >> l >> r >> w;
        edges.pb({w, l, r});
    }
    sort(all(edges));
    segtree st;
    st.init(m+1);
    int pos = 0;
    int res = 1e18;
    // for each index find the smallest index after it such that that segment is valid
    for(int i = 0;i<n;++i){
        int val = st.sol(2,m+1);
        if(val>=1){
            res = min(res, edges[pos-1][0]-edges[i][0]);
            
        }
        while(pos < n){
            int val = st.sol(2,m+1);
            if(val>=1){
                res = min(res, edges[pos-1][0]-edges[i][0]);
                break;
            }

            st.rangeupdate(edges[pos][1]+1,edges[pos][2]+1,1);
            val = st.sol(2,m+1);
            if(val>=1){
                res = min(res, edges[pos][0]-edges[i][0]);
                pos++;
                break;
            }
            pos++;

        }
        st.rangeupdate(edges[i][1]+1,edges[i][2]+1,-1);

    }
    cout << res << endl;
    // int l = -1, r = mx;
    // while(l+1 < r){
    //     int m = (l+r)/2;
    //     if(pos(m))r = m;
    //     else l = m;
    // }
    // cout << r << endl;
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