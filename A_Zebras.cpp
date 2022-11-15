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
    set<int>ones,zeroes;
    for(int i = 0;i<n;++i){
        if(s[i] == '0')zeroes.insert(i);
        else ones.insert(i);
    }
    vector<int>taken(n);
    vector<vector<int>>res;
    for(int i = 0;i<n;++i){
        if(taken[i])continue;
        if(s[i] == '1')continue;
        vector<int>sub = {i};
        int prev = i;
        bool m = 1;
        taken[i] = 1;
        while(1){
            if(m){
                if(ones.empty())break;
                auto pos = ones.upper_bound(prev);
                if(pos == ones.end())break;
                taken[*pos] = 1;

                sub.pb(*pos);
                prev = *pos;
                ones.erase(pos);
            }else{
                if(zeroes.empty())break;
                auto pos = zeroes.upper_bound(prev);
                if(pos == zeroes.end())break;
                sub.pb(*pos);
                prev = *pos;
                taken[*pos] = 1;
                zeroes.erase(pos);
            }
            m = !m;
        }
        if(s[sub.back()] == '1'){
            taken[sub.back()] = 0;
        }
        res.pb(sub);
    }
    for(int i = 0;i<n;++i){
        if(!taken[i]){
            cout << -1;
            return;
        }
    }
    cout << res.size() << endl;
    for(auto x: res){
        cout << x.size() <<' ';
        for(auto y : x)cout << y+1 << ' ';
        cout << endl;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}