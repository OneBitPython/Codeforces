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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int&u:a)cin >> u;

    int cnt = 0;
    vector<int>negvs, zeroes, pref2(n);
    for(int i = 0;i<n;++i){
        if(a[i] == 2 || a[i] == -2)cnt++;
        if(a[i]<0)negvs.pb(i);
        if(a[i] == 0)zeroes.pb(i);
        pref2[i] = cnt;
    }
    vector<int>negcnt(n);
    cnt = 0;
    for(int i = 0;i<n;++i){
        if(a[i] < 0)cnt++;
        negcnt[i] = cnt;    
    }

    int mx = 0;
    int lrange = 0, rrange = n-1; 
    for(int i = 0;i<n;++i){
        if(a[i] == 0)continue;
        // find the next zero that takes place
        int l = i;
        auto next_zero = lower_bound(all(zeroes), l);
        int pos = n;
        if(next_zero!=zeroes.end())pos = *next_zero;
        if(pos > 0)pos--;

        // pos is the position of the next zero - 1
        int neg = negcnt[pos];
        if(l > 0)neg-=negcnt[l-1];
        int pos2 = n-1;
        
        if(neg%2){
            // you have to remove the last negative number before pos
            auto nxt = upper_bound(all(negvs), pos) - negvs.begin() - 1;
            pos2 = negvs[nxt] - 1;
        }
        if(pos2 < 0 || pos < 0)continue;
        int r = min(pos, pos2);
        int c = pref2[r];
        if(l > 0)c-=pref2[l-1];

        if(c > mx){
            mx = c;
            lrange = l;
            rrange = r;
        }
    }
    if(mx == 0){
        cout << n << ' ' << 0 << endl;
    }else cout << lrange << ' ' << n-rrange-1 << endl;
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