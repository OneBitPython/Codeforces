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
    n*=2;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    sort(all(a));
    vector<int>taken(n+1);
    map<int,int>cnt;
    for(int i = 0;i<n;++i){
        if(taken[i])continue;
        for(int j = n-1;j>=0;--j){
            if(!taken[j] && i!=j){
                int c= cnt[a[i]-a[j]]+1;
                int got = (i+1);
                int lim = (got+1)/2;
                int c2 = cnt[a[j]-a[i]]+1;
                if(c <= lim){
                    taken[i] = 1;
                    taken[j] = 1;
                    cnt[a[i]-a[j]] = c;
                    break;
                }else if(c2 <= lim){
                    taken[i] = taken[j] = 1;
                    cnt[a[j]-a[i]]++;
                    break;
                }
            }
        }
        if(!taken[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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