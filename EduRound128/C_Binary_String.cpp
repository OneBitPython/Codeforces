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

vector<int>zero;
vector<int>prefix;
int n;
bool pos(int x){
    // try to check if you can keep x contiguous zeroes in such a way that <=x 1's are removed
    int m = zero.size();
    if(x>=m)return 1;
    for(int i = 0;i<m;++i){
        if(i + x - 1 >= m)break;
        int ones_before = 0, ones_after = 0;
        if(i-1 >= 0)ones_before+=(prefix[zero[i-1]]);
        if(i+x < m)ones_after+=(prefix[n-1]-prefix[zero[i+x]]);
        if(ones_before + ones_after <= x)return 1;
    }
    return 0;
}

void solve()
{
    string s;
    cin >> s;
    n = s.size();
    zero.clear();
    prefix.clear();
    int cnt = 0;
    for(int i = 0;i<n;++i){
        if(s[i] == '0')zero.pb(i);
        if(s[i] == '1')cnt++;
        prefix.pb(cnt);
    }
    int c = count(all(s), '0');
    for(int i = 0;i<n;++i){
        if(s[i] == '0')c--;
        else break;
    }
    for(int i = n-1;i>=0;--i){
        if(s[i] == '0')c--;
        else break;
    }
    if(c == 0){
        cout<< 0 << endl;
        return;
    }
    int l = -1, r = count(all(s), '1')+1;
    while(l+1 < r){
        int m = (l+r)/2;
        if(pos(m))r = m;
        else l = m;
    }
    cout << r << endl;
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