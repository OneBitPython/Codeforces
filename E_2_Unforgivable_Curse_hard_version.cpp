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
    int n,k;
    cin >> n >> k;
    string s,t;
    cin >> s >> t;
    vector<int>group(n,-1);
    queue<int>q;
    vector<int>visited(n);
    int curr = 1;
    for(int i = n-1;i>=0;--i){
        vector<int>c = {i};
        if(i-k >= 0){
            c.pb(i-k);
        }
        if(i-k-1 >=0)c.pb(i-k-1);
        int g = -1;
        for(auto x : c){
            if(group[x]!=-1)g = group[x];
        }
        if(g==-1)g = curr, curr++;
        for(auto x : c)group[x] = g;
    }
    int w = *max_element(all(group));
    vector<vector<int>>cnt(w+1,vector<int>(30));
    for(int i =0;i<n;++i){
        cnt[group[i]][s[i]-'a']++;
    }
    for(int i = 0;i<n;++i){
        if(s[i]==t[i])continue;
        if(cnt[group[i]][t[i]-'a']){
            cnt[group[i]][t[i]-'a']--;
            cnt[group[i]][s[i]-'a']++;
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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