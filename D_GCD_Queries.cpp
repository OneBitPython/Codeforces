#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
// #define endl "\n"

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

int query(int i, int j){
    cout << "? " << i << ' ' << j << endl;
    int k; cin >> k;
    return k;
}

void e(int i, int j){
    cout << "! " << i << ' ' << j << endl;
    int k;
    cin >> k;
}

int fr(set<int>&a){
    int x = *a.begin();
    a.erase(a.begin());
    return x;
}

void solve()
{
    int n;
    cin >> n;
    set<int>take;
    for(int i = 1;i<=n;++i)take.insert(i);
    if(n<=2){
        e(1,2);
        return;
    }
    while(take.size() > 2){
        int i = fr(take), j = fr(take), k = fr(take);
        int l = query(i,k), r = query(j,k);
        if(l==r){
            take.insert(i);
            take.insert(j);
            continue;
        }
        if(l > r){
            take.insert(i);
            take.insert(k);
            continue;
        }
        take.insert(j);
        take.insert(k);
    }
    e(fr(take),fr(take));
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