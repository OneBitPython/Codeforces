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
    if((x > 0 && y > 0) || (x==0 && y==0)){
        cout << -1 << endl;
        return;
    }
    if(y > x)swap(x,y);
    int val = 1;
    int cnt = 0;
    vector<int>res(n-1,-1);
    for(int i = 0;i<x;++i)res[i] = 1;
    int st = 1+x+1;
    int filled = x;
    while(filled < (n-1)){
        for(int j = 0;j<x;++j){
            if(filled >= (n-1)){
                cout << -1 << endl;
                return;
            }
            res[filled] = st;
            filled++;
        }
        st+=x;
    }

    for(auto x : res){
        if(x==-1){
            cout << -1 << endl;
            return;
        }
        
    }
    for(auto x : res){
        cout << x << ' ';
        
    }

    cout << endl;
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