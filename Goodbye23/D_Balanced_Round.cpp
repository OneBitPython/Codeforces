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
    int n = 10;
    int u = (1ll<<n);
    set<vector<int>>st;
    int res = 0;
    set<pair<vector<int>,vector<int>>>pp;
    for(int i = 0;i<u;++i){
        int cnt = 0;
        for(int j = 0;j<n;++j){
            if((i&(1ll<<j)))cnt++;
        }
        if(cnt==(n/2)){
            vector<int>right,left;
            for(int j = 0;j<n;++j){
                if((i&(1ll<<j)))right.pb(j);
                else left.pb(j);
            }
            do{
                do{
                    int mx1 = 0, mx2 = 0;
                    bool ok = 1;
                    for(int j = 0;j<(n/2);++j){
                        mx1 = max(mx1, right[j]);
                        mx2 = max(mx2, left[j]);
                        if(mx2 > mx1){
                            ok = 0;
                            break;
                        }
                    }
                    if(ok){
                        pp.insert({right,left});
                        // dbg(right,left);
                        res++;
                    }
                }while(next_permutation(all(left)));
            }while(next_permutation(all(right)));
        }
    }
    dbg(st);
    cout << pp.size();
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