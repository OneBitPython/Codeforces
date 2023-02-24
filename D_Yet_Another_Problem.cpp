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
    int n,q;
    cin >> n >> q;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    map<int,vector<int>>even,odd;
    vector<int>pref(n+1),pref2(n+1);
    for(int i = 1;i<=n;++i){
        pref[i] = pref[i-1]^a[i];
        pref2[i] = pref2[i-1]+(a[i]==0);
        if(i%2)odd[pref[i]].pb(i);
        else even[pref[i]].pb(i);
    }
    dbg(pref);
    while(q--){
        int l,r;
        cin >> l >> r;
        if((pref[r]^pref[l-1])!=0){
            cout << -1 << endl;
            continue;
        }
        if((pref2[r]-pref2[l-1])==(r-l+1)){
            cout << 0 << endl;
            continue;
        }
        if((r-l+1)%2){
            cout << 1 << endl;
            continue;
        }
        // could be either -1 or 2
        // you need to find two odd length subarrays each with xor 0
        // ie pref[r]==pref[k-1]==pref[l-1]
        // binary search to find if such a k exists
        bool ok = 0;
        if((l-1)%2){
            auto x = lower_bound(all(even[pref[l-1]]),l);
            if(x!=even[pref[l-1]].end()){
                int k = *lower_bound(all(even[pref[l-1]]), l);
                if(k>=l && k < r)ok = 1;
                if(ok){
                    if(pref2[k]-pref2[l-1] == (k-l+1) || (pref2[r]-pref2[k]==(r-k))){
                        cout << 1 << endl;
                        continue;
                    }
                }
                if(ok){
                    k = even[pref[l-1]][lower_bound(all(even[pref[l-1]]), r)-even[pref[l-1]].begin()-1];
                    if(pref2[k]-pref2[l-1] == (k-l+1) || (pref2[r]-pref2[k]==(r-k))){
                        cout << 1 << endl;
                        continue;
                    }
                }
            }
        }else{
            auto x = lower_bound(all(odd[pref[l-1]]),l);
            if(x!=odd[pref[l-1]].end()){
                int k = *lower_bound(all(odd[pref[l-1]]), l);
                if(k>=l && k < r)ok = 1;
                if(ok){
                    if(pref2[k]-pref2[l-1] == (k-l+1) || (pref2[r]-pref2[k]==(r-k))){
                        cout << 1 << endl;
                        continue;
                    }
                }
                if(ok){
                    k = odd[pref[l-1]][lower_bound(all(odd[pref[l-1]]), r)-odd[pref[l-1]].begin()-1];
                    if(pref2[k]-pref2[l-1] == (k-l+1) || (pref2[r]-pref2[k]==(r-k))){
                        cout << 1 << endl;
                        continue;
                    }
                }
            }
        }
        if(ok){
            cout << 2 << endl;
        }else cout << -1 << endl;
    }
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}