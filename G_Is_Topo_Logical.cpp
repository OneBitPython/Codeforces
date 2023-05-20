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
    int n;
    cin >> n;
    vector<int>initial(n+1),fina(n+1);
    for(int i= 1;i<=n;++i)cin >> initial[i];
    for(int i = 1;i<=n;++i)cin >> fina[i];
    vector<int>pos,zero; // >0 final degree and = 0 final degree
    for(int i = 1;i<=n;++i){
        if(fina[i]==0)zero.pb(i);
        else pos.pb(i);
    }
    vector<pair<int,int>>res;
    for(int i = 1;i<=n;++i){
        if(initial[i]==0)continue;

        int x = initial[i]-fina[i];
        int taken = 0;
        for(int j = 0;j<zero.size();++j){
            int v = zero[j];
            if(v==i)continue;
            if(taken==x)break;
            taken++;
            res.pb({v,i});
        }
        if(taken < x){
            res.clear();
            cout << -1 << endl;
            return;
        }
        taken = 0;
        for(int j = 0;j<pos.size();++j){
            int v = pos[j];
            if(v==i)continue;
            if(taken==fina[i])break;
            taken++;
            res.pb({v,i});
        }
        if(taken < fina[i]){
            cout << -1 << endl;
            res.clear();
            return;
        }
    }
    cout << res.size() << endl;
    for(auto x : res)cout << x.first << ' ' << x.second << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    freopen("topo.in", "r", stdin);
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