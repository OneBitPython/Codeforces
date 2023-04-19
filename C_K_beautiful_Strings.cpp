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
    string s;
    cin >> s;
    if((n%k)!=0){
        cout << -1 << endl;
        return;
    }
    int pos = 0;
    char c; 
    map<char,int>cnt;
    for(auto x : s)cnt[x]++;
    bool ok = 1;
    for(auto x : s){
        ok&=((cnt[x]%k)==0);
    }
    if(ok){
        cout << s << endl;
        return;
    }
    for(int i = n-1;i>=0;--i){
        cnt[s[i]]--;
        for(char x = s[i]+1;x<='z';++x){
            int get = 0;
            cnt[x]++;
            for(auto &[q,t] : cnt){
                get+=(((t/k)+((t%k)!=0))*k);
            }
            if(get <= n && (((n-get)%k) == 0)){
                string res;
                vector<pair<char,int>>d;
                for(int j = 0;j<i;++j)res+=s[j];

                for(auto &[q,t] : cnt)d.pb({q,t});
                sort(all(d));
                res+=x;
                for(int j = 0;j<n-get;++j)res+='a';
                for(auto x : d){
                    while((x.second%k) != 0){
                        x.second++;
                        res+=x.first;
                    }
                }
                cout << res << endl;
                return;
                
            }
            cnt[x]--;
        }
    }
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