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
    int n,k;
    cin >> n >> k;
    vector<vector<int>>a(n,vector<int>(k));
    map<vector<int>,int>mp;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<k;++j)cin >> a[i][j];
        mp[a[i]] = i;
    }
    int res = 0;
    for(int i = 0;i<n;++i){
        set<pair<int,int>>b;
        for(int j = 0;j<n;++j){
            if(i==j)continue;
            vector<int>need;
            for(int l = 0;l<k;++l){
                if(a[i][l] == a[j][l])need.pb(a[i][l]);
                else{
                    vector<bool>no(3,1);
                    no[a[i][l]] = 0;
                    no[a[j][l]] = 0;
                    for(int m = 0;m<3;++m){
                        if(no[m])need.pb(m);
                    }
                }
            }
            if(mp.count(need)){
                b.insert({min(j,mp[need]), max(j,mp[need])});
            }
        }
        int c = b.size();
        res+=((c*(c-1))/2);
    }
    cout << res;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}