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
    vector<int>a(n+1);
    for(int i =1 ;i<=n;++i)cin >> a[i];
    int m;
    cin >> m;
    vector<pair<int,int>>b = {{0,0}};
    for(int i = 1;i<=n;++i)b.pb({a[i],i});
    sort(b.begin()+1, b.end());
    int ptr = b.size()-1;
    int get = n-1, single = 0,black = 0;
    vector<int>taken(n+2); taken[0] = taken[n+1 ] = 1;
    int totused = 0;
    int res = 0;
    for(int i = n;i>=1;--i){
        if(ptr < 1)break;

        while(ptr >= 1 && b[ptr].first >= i){
            int pos = b[ptr].second;
            black++;
            taken[pos] = 1;
            if(pos>1 && taken[pos-2] && !taken[pos-1])single++;
            if(pos < n && taken[pos+2] && !taken[pos+1])single++;

            if(!taken[pos-1] && !taken[pos+1])get-=2;
            else if((taken[pos-1] && !taken[pos+1]) || (taken[pos+1] && !taken[pos-1]))get--;
            else if(taken[pos-1] && taken[pos+1])single--;

            ptr--;
        }
        int used = n-single-black;
        totused+=used;
        res+=get;
        if(totused > m){
            int cnt = 0;
            vector<int>group;
            for(int i = 1;i<=n;++i){
                if(!taken[i])cnt++;
                else{
                    if(cnt > 1)group.pb(cnt);
                    cnt = 0;
                }
            }
            if(cnt>1)group.pb(cnt);
            sort(all(group));
            for(auto x : group){
                int rem = min(x, totused-m);
                if(rem==0)break;
                if(rem < x)res-=rem,totused-=rem;
                else res-=(x-1),totused-=x;
            }
            break;
        }
        if(totused >= m)break;
    }
    dbg(totused);
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