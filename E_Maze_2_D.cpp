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

int n,q;
vector<int>id, sz;
int root(int x){
    if(x==id[x])return x;
    return id[x] = root(id[x]);
}

void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
}
int give(int i, int j){
    if(i==0)return j;
    return n+j;

}

int nxt(int x, vector<int>&a){
    int pos =  upper_bound(all(a),x)-a.begin();
    if(pos >= (int)(a.size()))return -1;
    return a[pos];
}
int bef(int x, vector<int>&a){
    int pos =  lower_bound(all(a),x)-a.begin()-1;
    if(pos < 0)return -1;
    return a[pos];
}
int row(int x){
    if(x < n)return 0;
    return 1;
}
void solve()
{
    cin >> n >> q;
    vector<vector<int>>a(2, vector<int>(n));
    for(int i = 0;i<2;++i){
        string s;
        cin >> s;
        for(int j = 0;j<n;++j){
            if(s[j]=='X')a[i][j] = 1;
        }
    }
    id.resize(3*n);
    iota(all(id),0ll);
    sz.resize(3*n,1);
    vector<pair<int,int>>shift = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    for(int i = 0;i<2;++i){
        for(int j = 0;j<n;++j){
            for(auto x : shift){
                int ni = i+x.first, nj = j+x.second;
                if(ni >= 0 && ni < 2 && nj >= 0 && nj < n && !a[i][j] && !a[ni][nj]){
                    merge(give(i,j),give(ni,nj));
                }
            }
        }
    }
    vector<int>first,second;
    for(int i = 0;i<1;++i){
        for(int j = 0;j<n;++j){
            if(a[i][j] && a[i+1][j])continue;
            if(a[i][j])first.pb(give(i,j));
            if(a[i+1][j])second.pb(give(i+1,j));
        }
    }
    vector<int>together;
    int x = 0, y = 0;
    while(x<first.size() && y < second.size()){
        if(first[x] < second[y]%n)together.pb(first[x]),x++;
        else together.pb(second[y]),y++;
    }
    while(x < (int)(first.size()))together.pb(first[x]),x++;
    while(y < (int)(second.size()))together.pb(second[y]),y++;
    map<int,int>pos;
    int g = 0;
    for(int i = 0;i<(int)(together.size());++i){
        if(i==0){
            pos[together[i]] = g;
            continue;
        }        
        if(row(together[i])!=row(together[i-1]))g++;
        pos[together[i]] = g;
    }
    while(q--){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        if(root(u)!=root(v)){
            cout << - 1 << endl;
            continue;
        }
        int res = 0;
        if(u < n && v < n){
            // both are on the first row
            if(v < u)swap(u,v);
            // find the next X after u and the first X before v
            // find their position in the together array
            int nx = nxt(u,first);
            int be = bef(v,first);
            res+=v-u;
            if(nx != -1 && nx < v){
                res+=(pos[be]-pos[nx]+2);
            }
        }else if(u >= n && v >= n){
            if(v < u)swap(u,v);
            int nx = nxt(u,second);
            int be = bef(v,second);
            res+=v-u;
            if(nx != -1 && nx < v){
                res+=(pos[be]-pos[nx]+2);
            }
        }else{
            // us column is less than v's column
            if((u%n) > (v%n))swap(u,v);
            if(row(u) < row(v)){
                int nx = nxt(u,first);
                int be = bef(v,second);
                int add = 1;
                if(be%n > u){
                    int x = bef(v%n,first);
                    if(x > be%n)be = x,add=0;
                }else be = nx,add=0;
                res+=((v%n)-u);
                if(nx != -1 && nx < v%n){
                    res+=(pos[be]-pos[nx]+1+add);
                }else res++;
            }else{
                // u is at the bottom v is on top
                int nx = nxt(u,second);
                int be = bef(v,first);
                int add = 1;
                if(be > (u%n)){
                    int x = bef(v+n, second);
                    if(x%n > be){
                        be = x;
                        add = 0;
                    }
                }else be = nx,add=0;
                res+=(v-(u%n));
                if(nx != -1 && nx%n < v){
                    res+=(pos[be]-pos[nx]+1+add);

                }else res++;
            }
        }
        cout << res << endl;
    }
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