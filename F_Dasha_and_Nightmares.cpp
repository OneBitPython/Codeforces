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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void solve()
{
    int n;
    cin >> n;
    /*
    represent a string by an integer, it has the xth bit on if the coutn of character x is odd
    split the strings into groups based on
    even and doesn't have the xth charaver
    odd and doesnt' have the xith character and keep a count denoting how many integers of type y exist in that group
    */
    vector<unordered_map<long long, int, custom_hash>>even(30), odd(30);

    vector<int>cnt(30);
    int res = 0;
    int t = 0;
    for(int j = 0;j<=25;++j)t+=(1ll<<j);

    for(int i = 0;i<n;++i){
        string s;
        cin >> s;
        int conv = 0;
        for(int j = 0;j<=26;++j)cnt[j] = 0;
        for(auto &x : s)cnt[x-'a']++;
        for(int j = 0;j<=25;++j){
            if(cnt[j]%2)conv+=(1ll<<j);
        }
        int m = s.size();
        for(int j = 0;j<=25;++j){
            int tot = t-(1ll<<j);
            if(cnt[j]==0){
                if(m%2){
                    res+=even[j][tot^conv];
                    odd[j][conv]++;
                }else{
                    res+=odd[j][tot^conv];
                    even[j][conv]++;
                }
            }
        }
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