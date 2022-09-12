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



void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int>res(m,-1);
    vector<vector<int>>a(n);
    map<int,int>cnt;
    for(int i = 0;i<m;++i){
        int k;
        cin >> k;
        vector<int>b;
        for(int j = 0;j<k;++j){
            int v;
            cin >> v;
            a[v-1].pb(i);
            cnt[v-1]++;
        }
    }
    vector<pair<int,int>>b;
    for(auto x: cnt){
        b.pb({x.second,x.first});
    }
    sort(all(b));
    dbg(b);
    for(int i = 0;i<b.size();++i){
        int select = 0;
        for(auto x : a[b[i].second]){
            if(select >= ((m+1)/2))break;
            if(res[x] != -1)continue;
            res[x] = b[i].second;
            select++;
        }
    }
    bool ok = 1;
    dbg(res);
    for(auto x: res){
        if(x==-1)ok = 0;
    }
    if(!ok){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(auto x : res)cout << x+1 << ' ';
    cout << endl;
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