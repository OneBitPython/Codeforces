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
    vector<pair<int,int>>seg(n+1);
    for(int i = 1;i<=n;++i)cin >> seg[i].first;
    for(int i = 1;i<=n;++i)cin >> seg[i].second;
    vector<int>b(n+1);
    for(int i= 1;i<=n;++i)b[i] = seg[i].second-seg[i].first + 1;
    int get = 0;
    vector<int>dp(n+1,1e18),least(n+1,1e18),used(n+1),dp2(n+1,-1);
    multiset<int>st;
    map<int,int>cnt,p;
    for(int i = 1;i<=n;++i){
        get+=b[i];
        st.insert(b[i]);
        cnt[b[i]]++;
        p[b[i]]++;
        while(!st.empty() && get >= k){
            int u = *st.begin();
            if((get-u) >= k){
                get-=u;
                cnt[u]--;
                st.erase(st.begin());
            }else break;
        }
        used[i] = cnt[b[i]]==p[b[i]];
        if(get>=k){
            dp[i] = st.size();
            if(cnt[b[i]])least[i] = get-b[i];
            else least[i] = get-*st.begin();
        }else dp2[i] = k-get;
    }
    int res = 1e18;
    dbg(dp,least);
    for(int i = 1;i<=n;++i){
        if(dp[i]==1e18)continue;
        int cost = (dp[i]*2)+(seg[i].second);
        res = min(res, cost);

        int left = k-least[i];
        cost = (dp[i]-1)*2;

        cost+=(seg[i].first+left-1+2);
        if(b[i] < left)cost = 1e18;
        res = min(res, cost);
        if(i > 1 && dp2[i-1]!=-1){
            left = dp2[i-1];
            cost = (i-1)*2;
            cost+=(seg[i].first+left-1+2);
            res = min(res, cost);
        }
    }
    if(res==1e18)res = -1;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}