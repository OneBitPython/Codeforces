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

string give(int x){
    string s;stringstream ss;
    ss << x;ss >> s;
    return s;
}
int n;
void print(vector<int>&order, int gap){
    cout << order[0];
    for(int i = 0;i<gap;++i)cout << "0";
    cout << order[1];
    for(int i = 0;i<gap;++i)cout << "0";
    cout << order[2];
    int left = n-3-(2*gap);
    for(int i = 0;i<left;++i)cout << "0";
    cout << endl;
}
void solve()
{
    cin >> n;
    int val = (n-3)/2;
    if(n==1){
        cout << 1 << endl;
        return;
    }
    for(int gap = val;gap>=0;--gap){
        vector<int>order = {1,6,9};
        print(order,gap);
        order = {9,6,1};
        print(order,gap);
    }
    cout << "196";
    for(int i = 0;i<n-3;++i)cout << "0";
    cout << endl;

}   
/*
4 - 133,137,281,286
5 - 375,405,504,645,708
*/

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