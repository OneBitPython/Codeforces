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
    int n,x,y;
    cin >> n >> x >> y;
    string a,b;
    cin >> a >> b;
    vector<int>c;
    for(int i = 0;i<n;++i){
        if(a[i]!=b[i])c.pb(i);
    }
    
    if(c.size()%2){
        cout << -1 << endl;
        return;
    }
    if(y<=x){
        if(c.size() == 2){
            if((c[0])!=(c[1]-1)){
                cout << y << endl;
                return;
            }
            cout << min(x, y*2) << endl;
            return;
        }
        int change = (int)(c.size())/2;
        cout << y*change << endl;

        return;
    }
    vector<pair<int,int>>pairs;
    
    int res = 0;
    for(int i = 0;i<(int)(c.size());i++){
        for(int j = i+1;j<(int)(c.size());++j){
            pairs.pb({c[i], c[j]});
        }
    }
    
    sort(all(pairs), [&](auto one, auto two){
        return (one.second - one.first) < (two.second-two.first);
    });
    vector<bool>taken(n+1);
    for(auto z : pairs){
        if(taken[z.first] || taken[z.second])continue;
        taken[z.first] = 1;
        taken[z.second] = 1;
        int dist = z.second-z.first;
        res+=min(y,dist*x);
    }
    cout << res << endl;
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