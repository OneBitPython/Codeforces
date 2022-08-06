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
    int n;
    cin >> n;
    int m = s.size();
    vector<string>a(n);

    for(int i = 0;i<n;++i)cin >> a[i];
    vector<vector<int>>re;
    for(int i = 0;i<m;++i){
        string t;
        for(int j = i;j<m;++j){
            t+=s[j];
            for(int q = 0;q<n;++q){
                string x = a[q];
                if(x == t){
                    re.pb({i, j, q});
                }
            }
        }
    }
    sort(all(re));
    // dbg(re);
    vector<vector<pair<int,int>>>ans(m); // stores idx, position till
    int done_till = 0;
    int idx = 0;
    bool got = 0;
    for(auto x : re){
        if(x[0] == 0){
            got = 1;
            if(x[1] >= done_till){
                done_till = max(done_till, x[1]);
                idx = x.back();
                got = 1;
            }

        }
    }
    if(!got){
        cout << -1 << endl;
        return;
    }
    for(int j = 0;j<=done_till;++j){
        ans[j].pb({idx, done_till});
    }
    // dbg(ans);
    for(int i = 0;i<(int)(re.size());++i){
        vector<pair<int,int>>values;
        int sz = 1e18;
        for(int j = re[i][0]-1;j<=min(re[i][1], done_till);++j){
            if(j < 0)continue;
            if(ans[j].size() < sz && ans[j].back().second >= (re[i][0]-1)){
                sz = ans[j].size();
                values = ans[j];
            }
        }
        if(values.empty())continue;

        values.pb({re[i].back(), re[i][1]});
        for(int j = re[i][0];j<=re[i][1];++j){
            if(ans[j].empty() || values.size() < ans[j].size())ans[j] = values;
        }
        done_till = max(done_till, re[i][1]);
    }
    if(ans.back().empty()){
        cout << -1 << endl;
        return;
    }
    if(ans.back().back().second != (m-1)){
        cout << -1 << endl;
        return;
    }
    cout << ans.back().size() << endl;
    for(auto x : ans.back()){
        cout << x.first+1 << ' ';
        cout << x.second - a[x.first].size()+2 << endl;
    }
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