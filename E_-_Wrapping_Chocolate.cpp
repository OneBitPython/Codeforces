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
    vector<pair<int,int>>a(n),b(m);
    for(int i = 0;i<n;++i)cin >>a[i].first;
    for(int i = 0;i<n;++i)cin >>a[i].second;
    for(int i = 0;i<m;++i)cin >> b[i].first;
    for(int i = 0;i<m;++i)cin >> b[i].second;

    sort(all(a));
    sort(all(b));
    int pos = m-1;
    multiset<int>g;
    for(int i = n-1;i>=0;--i){
        int j = pos;
        for(;j>=0;--j){
            if(b[j].first >= a[i].first){
                g.insert(b[j].second);
            }else break;
        }
        pos = j;
        auto pos = lower_bound(all(g),a[i].second);
        if(pos==g.end()){
            cout<< "No";
            return;
        }
        g.erase(pos);
    }
    cout << "Yes";
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