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
    vector<int>fire, ice;
    vector<pair<int,int>>a(n);
    for(int i = 0;i<n;++i){
        cin >> a[i].first;
    }
    for(int i = 0;i<n;++i)cin>> a[i].second;
    for(int i = 0;i<n;++i){
        if(a[i].first == 0)fire.pb(a[i].second);
        else ice.pb(a[i].second);
    }
    sort(all(fire),greater<int>());
    sort(all(ice),greater<int>());
    vector<pair<int,int>>res;
    int pos = 0, pos1 = 0;
    // fire ice fire ice
    if(!fire.empty())res.pb({0,fire.back()});
    if(!ice.empty())res.pb({1,ice.back()});

    while(1){
        if(pos >= (int)(fire.size())-1 && pos1 >= (int)(ice.size())-1)break;
        if(pos < (int)(fire.size())-1)res.pb({0,fire[pos]}),pos++;
        if(pos1 < (int)(ice.size())-1)res.pb({1, ice[pos1]}),pos1++;
    }
    int ans = res[0].second;
    for(int i = 1;i<(int)(res.size());++i){
        if(res[i].first != res[i-1].first)ans+=(res[i].second*2);
        else ans+=res[i].second;
    }
    sort(all(fire),greater<int>());
    sort(all(ice),greater<int>());
    // ice first ice first
    pos = 0;
    pos1 = 0;
    res.clear();
    if(!ice.empty())res.pb({1,ice.back()});
    if(!fire.empty())res.pb({0,fire.back()});

    while(1){
        if(pos >= (int)(fire.size())-1 && pos1 >= (int)(ice.size())-1)break;
        if(pos1 < (int)(ice.size())-1)res.pb({1, ice[pos1]}),pos1++;
        if(pos < (int)(fire.size())-1)res.pb({0,fire[pos]}),pos++;
        
        
    }
    int ans1 = res[0].second;
    for(int i = 1;i<n;++i){
        if(res[i].first != res[i-1].first)ans1+=(res[i].second*2);
        else ans1+=res[i].second;
    }
    cout << max(ans, ans1) << endl;
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