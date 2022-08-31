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
    map<string,int>cnt1, cnt2, cnt3;
    for(int i = 0;i<n;++i){
        string s;
        cin >> s;
        cnt1[s]++;
    }
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        cnt2[s]++;
    }
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        cnt3[s]++;
    }

    dbg(cnt3);
    vector<int>res(3);
    for(auto x : cnt1){
        if(x.second == 0)continue;

        if(cnt2[x.first] && cnt3[x.first])continue;
        if(cnt2[x.first] || cnt3[x.first])res[0]++;
        else res[0]+=3;
    }
    for(auto x : cnt2){
        if(x.second == 0)continue;

        if(cnt1[x.first] && cnt3[x.first])continue;
        if(cnt1[x.first] || cnt3[x.first])res[1]++;
        else res[1]+=3;
    }
    for(auto x : cnt3){
        dbg(x.first,x.second);
        if(x.second == 0)continue;
        if(cnt2[x.first] && cnt1[x.first])continue;
        if(cnt2[x.first] || cnt1[x.first])res[2]++;
        else res[2]+=3;
    }
    for(auto x : res)cout << x << ' ';
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