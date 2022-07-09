#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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


bool pos(int x, vector<int>dp){
    int change = 0;
    int n = dp.size();
    int l = 0, r = n-1;
    while(l < r){
        if(dp[r] <= x){
            r--;
            continue;
        }
        if(dp[l] > x){
            break;
        }
        int req = dp[r]-x;
        int max_times = (x-dp[l])/2;
        if(req <= max_times){
            dp[r] = x;
            r--;
            dp[l]+=(req*2);
        }else{
            dp[r]-=max_times;
            dp[l]+=(max_times*2);
            l++;
        }

    }
    bool ok = 1;
    for(int i = 0;i<n;++i){
        if(dp[i] > x)return 0;
    }
    return 1;
    
    
}

void solve()
{
    int n,m;
    cin >> n>> m;
    vector<int>dp(n); // min cost for ith guy
    for(int i = 1;i<=m;++i){    
        int v;
        cin >> v;
        v--;
        dp[v]++;
    }
    sort(all(dp));
    int l = 0, r = 1e18;
    while(l+1 < r){
        int m = (l+r)/2;
        if(pos(m, dp))r = m;
        else l = m;
    }
    cout << r << endl;
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