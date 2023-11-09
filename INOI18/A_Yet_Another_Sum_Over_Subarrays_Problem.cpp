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
    string s;
    cin >> s;
    s = "0"+s;
    stack<vector<int>>st;
    vector<int>pref(n+1);
    for(int i = 1;i<=n;++i)pref[i] = pref[i-1]+(s[i]-'0');
    int res = 0;
    vector<pair<int,int>>val(2*n+1); // val[i] stores {number of indexes having value = i, sum of pref[i-1]}
    int active = 0, sum = 0;
    dbg(pref);
    for(int i = 1;i<=n;++i){
        val[2*pref[i-1]-i+1].first++;
        val[2*pref[i-1]-i+1].second+=pref[i-1];
        int j = i;
        int prev = 2*pref[j-1]-(j-1), curr = 2*pref[j]-j;
        dbg(curr,prev,val);
        if(curr == prev+1)active+=val[curr].first,sum+=val[curr].second;
        else if(curr==(prev-1))active-=val[curr+1].first,sum-=val[curr+1].second;
        res+=(pref[j]*active)-sum;
    }
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}