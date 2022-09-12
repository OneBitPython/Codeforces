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
    int w,q;
    int n = s.size();
    cin >> w >> q;
    vector<int>pref(n);
    pref[0] = s[0]-'0';
    for(int i = 1;i<n;++i)pref[i] = pref[i-1]+(s[i]-'0');
    vector<vector<int>>a(10); // vector of all values which have remainder i modulo 9
    for(int i = w-1;i<n;++i){
        int sum = pref[i]- (i-w>=0?pref[i-w]:0);
        a[sum%9].pb(i-w+1);
    }
    while(q--){
        int l,r,k;
        cin >> l >> r >> k;
        r--;
        l--;
        int sum = pref[r]-(l>0?pref[l-1]:0);
        sum%=9;
        bool ok = 0;
        set<pair<int,int>>st;
        for(int i = 0;i<=9;++i){
            for(int j = 0;j<=9;++j){
                // find a range with sum%9 = i
                int val = (sum*i)+j;
                if(((val%9)!=k))continue;
                int first = 0;
                if(a[i].empty())continue;
                first = a[i][0];
                if(a[j].empty())continue;
                int second = -1;
                for(auto x : a[j]){
                    if(x==first)continue;
                    second =x;
                    break;
                }
                if(second==-1)break;
                st.insert({first+1, second+1});
            }
        }
        if(st.empty())cout << -1 << ' ' << -1 << endl;
        else {
            auto res = *st.begin();
            cout <<res.first << ' ' << res.second << endl;
        }
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