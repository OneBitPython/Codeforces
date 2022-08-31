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
    int n,k,b,s;
    cin >> n >> k >> b >> s;
    if((k*b) > s){
        cout << -1 << endl;
        return;
    }
    vector<int>res;
    int bound = n-1;
    if(b > 0){
        res.pb(k * b);
    }else bound = n;
    
    int rem = s-(k*b);
    // dbg(res, rem);
    for(int i = 0;i<bound;++i){
        if(rem >= (k-1)){
            res.pb(k-1);
            rem-=(k-1);
        }else{
            res.pb(rem);
            rem = 0;
        }

    }
    if(rem == 0){
        for(auto x : res)cout << x << ' ';
        cout << endl;
    }else{
        for(int i = 0;i<n;++i){
            int add = (k-(res[i]%k))-1;
            if(rem<=add){
                res[i]+=rem;
                rem = 0;
            }else{
                res[i]+=add;
                rem-=add;
            }
        }
        if(rem == 0){
            for(auto x : res)cout << x << ' ';
            cout << endl;
        }else cout << -1 << endl;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}