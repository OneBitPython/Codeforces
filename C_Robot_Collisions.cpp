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

int n,k;
vector<int>res;
map<int,int>pp;
void f(vector<int>&a, vector<char>&pos){
    int m = a.size()-1;
    // a = position of all values, pos = inital direction, pp[x] = position of value x based on intiial array from input
    if(m==0)return;
    map<int,int>p; // p[x] latest position in which prefix sum x was reached
    int sum = 0;
    p[0] = 0;
    map<int,int>del;
    for(int i= 1;i<=m;++i){
        if(pos[i]=='L')sum++;
        else sum--;
        if(pos[i] == 'L' && p.count(sum)){
            int v = p[sum]+1;
            del[a[i]] = del[a[v]] = 1;
            res[pp[a[i]]] = (a[i]-a[v])/2;
            res[pp[a[v]]] = res[pp[a[i]]];
        }
        p[sum] = i;
    }
    vector<int>R,L;
    for(int i = 1;i<=m;++i){
        if(del[a[i]])continue;
        if(pos[i] == 'L')L.pb(a[i]);
        else R.pb(a[i]);
    }
    for(int i = (int)(R.size())-1;i>=1;i-=2){
        int u = R[i], v = R[i-1];
        del[u] = del[v] = 1;
        res[pp[u]] = res[pp[v]] = (k-u)+((u-v)/2);
    }
    for(int i = 0;i<(int)(L.size());i+=2){
        if(i+1 >= (int)(L.size()))break;
        int u = L[i], v = L[i+1];
        del[u] = del[v] = 1;
        res[pp[u]] = res[pp[v]] = (u+(v-u)/2);
    }
    if((int)(L.size())%2 && (int)(R.size())%2){
        int u = L.back(), v= R.front(); // R is to the right of L
        int c = 0;
        if((k-v)>=u){
            u = (k-v)-u;
            c+=(k-v);
            v+=(k-v);

        }else{
            c+=u;
            v = (k-(u-(k-v)));
            u = 0;
        }
        c+=(v-u)/2;
        res[pp[L.back()]] = res[pp[R.front()]] = c;
    }
}
void solve()
{
    cin >> n >> k;
    vector<int>a(n+1);
    vector<char>pos(n+1);
    res = vector<int>(n+1,-1);
    pp.clear();

    vector<pair<int,char>>together(n+1);
    for(int i = 1;i<=n;++i)cin >> together[i].first;
    for(int i = 1;i<=n;++i)cin >> together[i].second;

    for(int i = 1;i<=n;++i)pp[together[i].first] = i;

    sort(together.begin()+1, together.end());
    for(int i = 1;i<=n;++i)a[i] = together[i].first, pos[i] = together[i].second;

    vector<int>b = {0};
    vector<char>c = {'L'};
    
    for(int i= 1;i<=n;++i){
        if(a[i]%2)b.pb(a[i]),c.pb(pos[i]);
    }

    f(b,c);
    b = {0};
    c = {'L'};
    for(int i = 1;i<=n;++i){
        if((a[i]%2) == 0)b.pb(a[i]),c.pb(pos[i]);
    }
    f(b,c);
    for(int i = 1;i<=n;++i)cout << res[i] << ' ';
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