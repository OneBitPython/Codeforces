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
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<char,int>>a;
    for(int i = 0;i<n;++i)a.pb({s[i], i});
    
    vector<int>res;
    if(s[0] > s[n-1]){
        sort(all(a), [&](auto one, auto two){
            if(one.first != two.first)return one.first > two.first;
            return one.second < two.second;
        });
        for(int i = 0;i<n;++i){
            if(a[i].first <= s[0] && a[i].first >= s[n-1])res.pb(a[i].second);
        }
    }else{
        sort(all(a), [&](auto one, auto two){
            if(one.first != two.first)return one.first < two.first;
            return one.second < two.second;
        });
        for(int i = 0;i<n;++i){
            if(a[i].first >= s[0] && a[i].first <= s[n-1])res.pb(a[i].second);
        }
    }
    cout << (abs(s[0]-s[n-1])) << ' ' <<res.size() << endl;
    for(auto x : res)cout << x+1 << ' ';
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