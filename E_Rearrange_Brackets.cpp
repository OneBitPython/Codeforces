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

int cost(const string &s){
    stack<int>st;
    int n = s.size();
    int res = 0;
    for(int i = 0;i<n;++i){
        if(s[i]=='(')st.push(i);
        else{
            int v = st.top();
            st.pop();
            res+=(i-v+1-2)/2;
        }
    }
    return res;
}

void solve()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    vector<string>group;
    int cnt0 = 0, cnt1 = 0;
    string curr;
    for(int i = 0;i<s.size();++i){
        if(s[i]=='(')cnt0++;
        else cnt1++;
        curr+=s[i];
        if(cnt1==cnt0){
            group.pb(curr);
            curr.clear();
        }
    }
    int m = group.size();
    vector<vector<int>>a(m,vector<int>(k+1));
    vector<string>gg;
    for(int i = 0;i<m;++i){
        a[i][0] = cost(group[i]);
        gg.clear();
        gg.pb(group[i]);
        for(int j = 1;j<=k;++j){
            vector<string>ng;
            int mx = 0,pos=0;
            int res = 0;
            for(auto x : gg){
                int cnt1 = 0,cnt0=0;
                string curr;
                for(int l = 0;l<x.size();++l){
                    if(x[l]=='(')cnt0++;
                    else cnt1++;
                    curr+=x[l];
                    if(cnt0==cnt1){
                        ng.pb(curr);
                        res+=cost(curr);
                        if((int)(curr.size()) > mx){
                            mx = (int)(curr.size());
                            pos = ng.size()-1;
                        }
                        curr.clear();
                    }
                }
            }
            res-=(mx-2)/2;
            a[i][j] = res;
            if(mx>2){
                ng[pos].erase(ng[pos].begin());
                ng[pos].pop_back();
            }
            gg = ng;
        }
    }  
    vector<vector<int>>dp(m, vector<int>(k+1,1e18)); // dp[i][j] stores the min cost till group[i] if you make j changes till position i
    for(int j = 0;j<=k;++j)dp[0][j] = a[0][j];
    for(int i = 1;i<m;++i){
        for(int j = 0;j<=k;++j){
            for(int l = 0;l<=j;++l)dp[i][j] = min(dp[i][j],dp[i-1][j-l]+a[i][l]);
        }
    }
    cout << *min_element(all(dp[m-1])) << endl;
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