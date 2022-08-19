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
    int n,q;
    cin >> n >> q;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    vector<int>pref(n);
    pref[0] = a[0];
    for(int i = 1;i<n;++i)pref[i] = max(pref[i-1], a[i]);
    vector<int>pos(n+1);
    for(int i = 0;i<n;++i){
        pos[a[i]] = i;
    }
    set<int>st;
    for(int i = 1;i<=n;++i)st.insert(pos[i]);
    vector<int>gre(n+1); // gre[i] stores first value to the right of index i which is greater than a[i]
    gre[n] = 1e18;
    for(int i = 1;i<n;++i){
        st.erase(pos[i]);
        auto p = st.upper_bound(pos[i]);
        if(p == st.end())gre[i] = 1e18;
        else{
            gre[i] = *p;
        }
    }
    while(q--){
        int i,k;
        cin >> i >> k;
        i--;
        if(i == 0){
            int idx = gre[a[i]];
            cout << min(k, idx-i-1) << endl;
        }else{
            if(pref[i-1] > a[i])cout << 0 << endl;
            else{
                k-=i;
                int idx = gre[a[i]];
                if(k < 0){
                    cout << 0 << endl;
                    continue;
                }
                if(idx == 1e18){
                    cout << 1+k << endl;
                    continue;
                }
                if(k == 0)cout << 1 << endl;
                else{
                    cout << 1+min(k, idx-i-1) << endl;
                }
            }
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