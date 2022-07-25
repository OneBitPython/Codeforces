#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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
    int x;
    cin >> x;
    int n = s.size();
    vector<char>res(n,'x');
    for(int i = 0;i<x;++i){
        if(i+x<n){
            res[i+x] = s[i];
        }
    }
    for(int i = n-1;i>=n-x;--i){
        if(i-x >= 0){
            res[i-x] = s[i];
        }
    }
    bool ok = 1;
    for(int i = x;i<n-x;++i){
        // try for left if possible
        if(s[i] == '1'){
            if(res[i-x]=='1' || res[i+x] == '1')continue;
            if(res[i-x] != '0')res[i-x] = '1';
            else{
                if(res[i+x] != '0')res[i+x] = '1';
                else ok = 0;
            }
        }else{
            // both have to be set to 0
            if(res[i-x]=='1' || res[i+x] == '1'){
                ok = 0;
                continue;
            }
            if(res[i-x] == '0' && res[i+x] == '0')continue;
            res[i-x] = '0';
            res[i+x] = '0';
        }
    }
    string formed;
    for(int i = 0;i<n;++i){
        if(res[i] == 'x')res[i] = '1';
    }
    for(int i = 0;i<n;++i){
        bool got = 0;
        if(i-x >= 0){
            if(res[i-x] == '1')got = 1;
        }
        if(i+x < n){
            if(res[i+x] == '1')got = 1;
        }
        if(got)formed+='1';
        else formed+='0';
    }
    if(formed == s && ok){
        for(auto x : res)cout << x;
        cout << endl;
    }else cout << -1 << endl;
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