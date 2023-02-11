#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
// #define endl "\n"

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

int query(int a, int b, int c){
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    int ret;cin >> ret;
    return !ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<int>taken(n+1);
    vector<int>val(n+1);
    vector<int>good,bad;
    for(int i = 1;i<=n;i+=3){
        if(query(i,i+1,i+2))good = {i,i+1,i+2};
        else bad = {i,i+1,i+2};
    }
    vector<int>q;
    for(int i = 0;i<3;++i){
        for(int j = 0;j<2;++j)q.pb(query(good[i],bad[j],bad[j+1]));
    }
    for(auto x : good)taken[x] = 1;
    int g = -1, b = -1;
    if(*max_element(all(q))==0){
        // all values in the bad group are crew members
        for(auto x : bad)taken[x] = 1;

        bool ok1 = query(good[0],good[1],bad[0]), ok2 = query(good[0],good[2],bad[0]);
        if(!ok1 && !ok2){
            val[good[1]] = 1;
            val[good[2]] = 1;
        }else{
            val[good[0]] = 1;
            if(ok1)val[good[1]] = 1;
            if(ok2)val[good[2]] = 1;
        }
    }else{
        for(int i = 0;i<6;i+=2){
            if(q[i]||q[i+1]){
                val[good[i/2]] = 1;
                if(q[i]&&q[i+1])b = bad[0];
                else if(q[i])b = bad[2];
                else if(q[i+1])b = bad[0];
            }
        }
    }
    for(int i = 1;i<=n;++i){
        if(taken[i]&&val[i])g = i;
        else if(taken[i]&&!val[i])b=i;
    }
    taken[g] = 1;
    taken[b] = 1;

    for(int i = 1;i<=n;++i){
        if(taken[i])continue;
        if(query(g,b,i))val[i] = 1;
    }
    int k = accumulate(all(val),0ll);
    cout << "! " << k << ' ';
    for(int i = 1;i<=n;++i){
        if(val[i])cout << i << ' ';
    }
    cout << endl;
}   

int32_t main()
{

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

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