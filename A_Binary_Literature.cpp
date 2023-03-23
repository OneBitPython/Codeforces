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

int n;
bool f(string s, string t){
    int c = count(all(s),'0'), c1 = count(all(t),'0');
    string res;
    if(c >= n && c1 >= n){
        vector<pair<int,int>>a(n);
        int c = 0;
        for(int i= 0;i<2*n;++i){
            if(s[i]=='0')a[c].first = i, c++;
            if(c >= n)break;
        }
        c = 0;
        for(int i = 0;i<2*n;++i){
            if(t[i]=='0')a[c].second = i, c++;
            if(c>=n)break;
        }
        int p1 = 0, p2 = 0;
        for(auto x : a){
            while(p1 < x.first)res+=s[p1],p1++;
            while(p2 < x.second)res+=t[p2],p2++;
            res+='0';
            p1++;
            p2++;
        }
        while(p1 < 2*n)res+=s[p1],p1++;
        while(p2 < 2*n)res+=t[p2],p2++;
        cout << res << endl;
        return 1;
    }else{
        c = (2*n)-c;
        c1 = (2*n)-c1;
        if(c < n || c1 < n)return 0;
        vector<pair<int,int>>a(n);
        int c = 0;
        for(int i= 0;i<2*n;++i){
            if(s[i]=='1')a[c].first = i, c++;
            if(c >= n)break;
        }
        c = 0;
        for(int i = 0;i<2*n;++i){
            if(t[i]=='1')a[c].second = i, c++;
            if(c>=n)break;
        }
        int p1 = 0, p2 = 0;
        for(auto x : a){
            while(p1 < x.first)res+=s[p1],p1++;
            while(p2 < x.second)res+=t[p2],p2++;
            res+='1';
            p1++;
            p2++;
        }
        while(p1 < 2*n)res+=s[p1],p1++;
        while(p2 < 2*n)res+=t[p2],p2++;
        cout << res << endl;
        return 1;
    }
    return 0;
}
void solve()
{
    cin >> n;
    string a,b,c;
    cin >> a >> b >> c;
    if(f(a,b))return;
    if(f(b,c))return;
    if(f(a,c))return;
    assert(false);
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