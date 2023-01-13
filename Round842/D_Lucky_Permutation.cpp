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

//https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
int minSwaps(vector<int>&arr, int n)
{
    // Create an array of
    // pairs where first
    // element is array element
    // and second element
    // is position of first element
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++) {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
 
    // Sort the array by array
    // element values to
    // get right position of
    // every element as second
    // element of pair.
    sort(arrPos, arrPos + n);
 
    // To keep track of visited elements.
    // Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);
 
    // Initialize result
    int ans = 0;
 
    // Traverse array elements
    for (int i = 0; i < n; i++) {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;
 
        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = 1;
 
            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
 
        // Update answer by adding current cycle.
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }
 
    // Return result
    return ans;
}
struct segtree{
    int size =1;
    vector<int> arr;
    void init(int n){
        while(size < n)size*=2;
        arr.resize(size*2, 0);
    }
 
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            arr[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m){
            set(i, v, 2*x+1, lx, m);
        }else{
            set(i, v, 2*x+2, m, rx);
        }
        arr[x] = arr[2*x+1]+arr[2*x+2];
    }
 
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
 
    int sum(int l, int r, int x, int lx, int rx){
        if(lx>=r || rx<=l)return 0;
        if(lx>=l && rx<=r)return arr[x];
        int m = (lx+rx)/2;
        int right = sum(l,r,2*x+2,m,rx);
        int left = sum(l,r,2*x+1,lx,m);
        return right+left;
    }
 
    int sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
};

int c(vector<int>a){
    segtree st;
    int n = a.size();
    st.init(n+1);
    int inv = 0;
    for(int i = 0;i<n;++i){
        st.set(a[i], 1);
        inv+=st.sum(a[i]+1,n+1);
    }
    return inv;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<vector<int>>adj(n+1);
    vector<int>par(n+1);
    vector<int>visited(n+1);
    for(int i = 1;i<=n;++i)adj[i].pb(a[i]),par[i]=a[i];
    int has = 1;
    int res = 0;
    for(int i = 1;i<=n;++i){
        if(!visited[i]){
            int req = i;
            set<int>nodes;
            while(1){
                nodes.insert(req);
                visited[req] = 1;
                req = par[req];
                
                if(req==i)break;
            }
            for(auto x: nodes){
                if(nodes.count(x+1))has = -1;
            }
            res+=(int)(nodes.size())-1;
        }
    }
    cout << res+has << endl;
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