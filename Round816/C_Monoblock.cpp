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
    cin>> n >> m;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<int>cost(n+1);
    int sum = n;
    cost[1] = (n);
    
    for(int i = 2;i<=n;++i){
        if(a[i] == a[i-1])cost[i] = (n-i+1);
        else cost[i] = (n-i+1)*i;
        sum+=cost[i];
    }
    while(m--){
        int i,x;
        cin >> i >> x;
        a[i] = x;
        
        if(i > 1){
            
            if(a[i] == a[i-1]){
                int new_cost = n-i+1;
                sum-=(cost[i] - new_cost);
                cost[i] = new_cost;
            }else{
                int new_cost = (n-i+1)*i;
                sum-=(cost[i] - new_cost);
                cost[i] = new_cost;
            }
        }
        if(i < n){
            if(a[i] == a[i+1]){
                int new_cost = n-i;
                sum-=(cost[i+1] - new_cost);
                cost[i+1] = new_cost;
            }else{
                int new_cost1 = (n-i)*(i+1);
                sum-=(cost[i+1]-new_cost1);
                cost[i+1] = new_cost1;

            }
        }
        cout << sum << endl;
    }
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