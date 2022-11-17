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
    int n,q;
    cin >> n >> q;
    vector<int>a(n);
    for(int&U : a)cin >> U;
    vector<vector<int>>pref(n, vector<int>(61));
    for(int i = 0;i<=60;++i){
        int c = 0;
        for(int j = 0;j<n;++j){
            if(a[j] & (1ll<<i))c++;
            pref[j][i] = c;
        }
    }
    while(q--){
        int k,l1,r1,l2,r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        --l1;
        --l2;
        --r1;
        --r2;
        int res = 0;
        // find number of set bits in l1->l2
        int setf = pref[r1][k]-(l1>0?pref[l1-1][k]:0);
        int unsetf = (r1-l1+1) - setf;

        int sets = pref[r2][k] - (l2 > 0?pref[l2-1][k]:0);
        int unsets = (r2-l2+1)-sets;
        cout << (setf * unsets)+(unsetf * sets) << endl;
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