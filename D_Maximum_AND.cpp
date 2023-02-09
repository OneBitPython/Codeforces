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
    vector<int>a(n), b(n);
    for(int &u : a)cin >> u;
    for(int &u : b)cin >> u;
    vector<vector<int>>groups;
    groups.pb({});
    for(int i = 0;i<2*n;++i)groups[0].pb(i);
    int res = 0;
    for(int i = 30;i>=0;--i){
        // go through all the groups and count the number of values which have set bit in the ith position in a and unset in b or viceversa
        // if the count is equal in all groups then you can split
        bool ok = 1;
        for(int j =0;j<(int)(groups.size());++j){
            int seta = 0, unseta = 0, setb = 0, unsetb = 0;
            for(auto x : groups[j]){
                if(x<n)seta+=((a[x]&(1ll<<i))?1:0), unseta+=((a[x]&(1ll<<i))?0:1);
                int y = x-n;
                if(y>=0)setb+=((b[y]&(1ll<<i))?1:0), unsetb+=((b[y]&(1ll<<i))?0:1);;
            }
            if(seta!=unsetb || unseta!=setb)ok = 0;
        }
        vector<vector<int>>ne;
        if(ok){
            for(int j = 0;j<(int)(groups.size());++j){
                vector<int>st,unset; // store the index of all the values that are set in a and unset in b or set in b and unset in a
                for(auto x : groups[j]){
                    if(x<n){
                        if((a[x]&(1ll<<i)))st.pb(x);
                        else unset.pb(x);
                    }
                    int y = x-n;
                    if(y>=0){
                        if((b[y]&(1ll<<i)))unset.pb(x);
                        else st.pb(x);
                    }
                }
                if(!st.empty())ne.pb(st);
                if(!unset.empty())ne.pb(unset);
            }
            res+=(1ll<<i);
            groups = ne;
        }
    }
    cout << res << endl;
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