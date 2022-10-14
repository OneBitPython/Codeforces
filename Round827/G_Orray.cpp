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
    vector<int>a(n);
    for(int &u : a)cin >> u;
    vector<vector<bool>>dp(31,vector<bool>(n));
    sort(all(a));
    reverse(all(a));
    vector<int> res;
    res.pb(a[0]);
    multiset<int>rem;
    map<int,int>taken,pres;
    for(int j = 1;j<n;++j){
        int x = a[j];
        pres[x]++;
        rem.insert(x);
        for(int i = 0;i<=30;++i){
            if(x&(1ll<<i))dp[i][j] = 1;
        }
    }
    int val = res[0];
    for(int i= 0;i<n-1;++i){
        bool ok = 0;
        for(int j = 30;j>=0;--j){
            if((val&(1ll<<j))){

            }else{
                if(dp[j].empty())continue;
                int mx = -1e18, node = -1;
                for(int k = 1;k<n;++k){
                    if(!dp[j][k])continue;
                    if(taken[a[k]]>=pres[a[k]])continue;
                    int t = (a[k]|val);
                    if(t > mx){
                        mx = t;
                        node = a[k];
                    }
                }
                if(node==-1){
                    dp[j].clear();
                    continue;
                }
                res.pb(node);
                ok = 1;
                rem.erase(find(all(rem),node));
                taken[node]++;
                break;
            }
        }
        if(!ok){
            int u = *rem.begin();
            rem.erase(rem.begin());
            taken[u]++;
            res.pb(u);
        }
        val|=res.back();
    }
    for(auto x : res)cout << x << ' ';
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