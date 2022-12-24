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

int mx(vector<int>&a){
    set<int>b(all(a));
    for(int i = 0;i<(int)(b.size())+1;++i){
        if(b.count(i)==0)return i;
    }
    return b.size();
}

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    vector<int>res;
    for(int i = 0;i<n;++i){
        // set a[i] to i
        if(a[i]==i)continue;
        while(1){
            int mex = mx(a);
            if(mex==i){
                res.pb(i+1);
                a[i] = mex;
                break;
            }
            if(mex < n){
                if(a[mex]!=mex){
                    res.pb(mex+1);
                    a[mex] = mex;
                    continue;
                }
            }
            for(int j = 0;j<n;++j){
                if(a[j]==i){
                    res.pb(j+1);
                    a[j] = mex;
                    break;
                }
            }
        }
        bool ok = 1;
        for(int j = 0;j<n-1;++j){
            if(a[j] > a[j+1])ok = 0;
        }
        if(ok)break;
    }
    assert(res.size()<=(2*n));
    cout << res.size() << endl;
    for(auto x : res)cout << x << ' ';
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