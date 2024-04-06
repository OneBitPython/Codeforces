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
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,int>>a(m+1);
    vector<int>p(n+2);
    for(int i = 1;i<=m;++i)cin >> a[i].first >> a[i].second,p[a[i].first]++,p[a[i].second+1]--;

    sort(all(a));

    vector<int>cnt(n+1),pref1(n+1),pref2(n+1);
    int res = 0;
    for(int i = 1;i<=n;++i){
        cnt[i] = cnt[i-1] + p[i];
        pref1[i] = pref1[i-1];
        pref2[i] = pref2[i-1];
        if(cnt[i] == 1)pref1[i]++;
        else if(cnt[i]==2)pref2[i]++;
        else if(cnt[i]==0)res++;
        
    }

    vector<int>cc;
    for(int i =1;i<=m;++i)cc.pb(pref1[a[i].second] - pref1[a[i].first-1]);
    sort(all(cc),greater<int>());
    int ans = res + cc[0] + cc[1];
    set<int>st;

    int ptr = 1;

    for(int i =1;i<=n;++i){
        if(cnt[i]==2){
            set<int>stt;
            for(auto x : st){
                if(a[x].first <= i && a[x].second >= i)stt.insert(x);
            }
            st = stt;
            while(ptr <= m){
                if(a[ptr].first > i)break;
                if(a[ptr].first <= i && a[ptr].second >= i)st.insert(ptr);
                ptr++;
            }
            dbg(st.size());
            int fr = *st.begin(), sr = *(--st.end());
            int val = res + pref1[a[fr].second] - pref1[a[fr].first-1]+ pref1[a[sr].second] - pref1[a[sr].first-1] + pref2[min(a[fr].second,a[sr].second)] - pref2[max(a[fr].first, a[sr].first)-1];
            ans = max(ans, val);
        }
    }
    cout << ans << endl;

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