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
    vector<int>a(n+1), b(n+1);
    vector<pair<int,int>>bb(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=n;++i)cin >> b[i],bb[i].first = b[i], bb[i].second = i;
    sort(all(bb));
    for(int i = 1;i<=n;++i){
        int pos = bb[i].second, st = bb[i].first;
        if(a[pos]==b[pos])continue;
        if(a[pos] > b[pos]){
            cout << "NO" << endl;
            return;
        }
        // search for a value to the left whose a[j] = b[pos]
        // you can't use that j if minb(j,pos) < b[pos]
        int mn = 1e18;
        bool got = 0;
        for(int j = pos-1;j>=1;--j){
            mn = min(mn, b[j]);
            if(a[j] > b[pos])break;
            if(mn < b[pos]){
                break;
            }
            if(a[j] == b[pos]){
                got = 1;
                for(int k = j;k<=pos;++k){
                    a[k] = a[j];
                }
                break;
            }
        }
        if(!got){
            mn = 1e18;
            for(int j = pos+1;j<=n;++j){
                mn = min(mn,b[j]);
                if(a[j] > b[pos])break;

                if(mn < b[pos]){
                    break;
                }
                if(a[j]==b[pos]){
                    got = 1;
                    for(int k = pos;k<=j;++k)a[k] = a[j];
                    break;
                }
            }
        }
        if(!got){
            cout << "NO" << endl;
            return;
        }
        for(int j =  1;j<=n;++j){
            if(a[j] > b[j]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    bool ok = 1;
    for(int i = 1;i<=n;++i){
        if(a[i]!=b[i])ok = 0;
    }
    cout << (ok?"YES":"NO") << endl;
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