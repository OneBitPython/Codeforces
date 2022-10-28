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
    vector<int>a(n);
    for(int &u : a)cin >> u;
    int one = count(all(a),1), inv = count(all(a),-1);
    vector<pair<int,int>>res;
    if(inv < one){
        int rem = (one-inv);
        if(rem%2==1){
            cout << -1 << endl;
            return;
        }
        vector<bool>taken(n);
        for(int i = 0;i<n-1;++i){
            if(taken[i])continue;
            if(a[i] == 1 && a[i+1] == 1 && rem > 0){
                res.pb({i,i+1});
                taken[i] = 1;
                taken[i+1] = 1;
                rem-=2;

            }
        }
        for(int i = 0;i<n;++i){
            if(a[i] == -1){
                res.pb({i,i});
                taken[i] = 1;
            }
            if(!taken[i] && a[i] == 1){
                res.pb({i,i});
                taken[i] = 1;
            }
        }
        for(int i = 0;i<n;++i){
            if(!taken[i]){
                cout << -1 << endl;
                return;
            }
        }
    }else{
        int rem = inv - one;
        if(rem%2==1){
            cout << -1 << endl;
            return;
        }
        vector<bool>taken(n);
        for(int i = 0;i<n-1;++i){
            if(taken[i])continue;
            if(a[i] == -1 && a[i+1] == -1 && rem > 0){
                res.pb({i,i+1});
                taken[i] = 1;
                taken[i+1] = 1;
                rem-=2;

            }
        }
        for(int i = 0;i<n;++i){
            if(a[i] == 1){
                res.pb({i,i});
                taken[i] = 1;
            }
            if(!taken[i] && a[i] == -1){
                res.pb({i,i});
                taken[i] = 1;
            }
        }
        for(int i = 0;i<n;++i){
            if(!taken[i]){
                cout << -1 << endl;
                return;
            }
        }
    }
    sort(all(res));
    cout << res.size() << endl;
    for(auto x : res)cout << x.first+1 << ' ' << x.second+1 << endl;
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