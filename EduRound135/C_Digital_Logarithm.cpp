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


int sz(int x){
    int l = 0;
    while(x){
        l++;
        x/=10;
    }
    return l;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n),b(n);
    for(int &u : a)cin >> u;
    for(int &u : b)cin >> u;
    map<int,set<int>>mc;
    for(int i = 0;i<n;++i){
        mc[b[i]].insert(i);
    }
    vector<int>vis1(n),vis2(n);
    int res = 0;
    for(int i = 0;i<n;++i){
        if(mc[a[i]].size()>0){
            vis1[i] = 1;
            vis2[*mc[a[i]].begin()] = 1;
            mc[a[i]].erase(mc[a[i]].begin());
        }
    }
    vector<set<int>>mp(11);
    for(int i = 0;i<n;++i){
        if(vis2[i])continue;
        if(b[i]<10)mp[b[i]].insert(i);
        else mp[sz(b[i])].insert(i);
    }
    for(int i = 0;i<n;++i){
        if(vis1[i])continue;
        int val = a[i];
        int c = 0;
        if(val>=10)val = sz(a[i]),c=1;

        if(!mp[val].empty()){
            int u = *mp[val].begin();
            mp[val].erase(mp[val].begin());
            if(b[u] >= 10)c++;
            vis1[i] = 1;
            vis2[u] = 1;
            res+=c;
        }
    }
    for(int i = 0;i<n;++i){
        if(!vis1[i]){
            if(a[i] == 1){}
            else if(a[i] < 10)res++;
            else res+=2;
        }
        if(!vis2[i]){
            if(b[i] == 1)continue;
            if(b[i] < 10)res++;
            else res+=2;
        }
    }
    cout << res << endl;
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