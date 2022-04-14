#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"
#define inf 1e18

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

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}


int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n){
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        val+="1";
      }
      else
      {
        val+="0";
      }
    }
    while(val.front()=='0'){
        val.erase(0,1);
    }
    return val;
}


struct edge{
    int s,e,c;
};

void solve()
{
    int n;

    cin >> n;
    vector<edge>a(n);
    for(int i = 0;i<n;++i){
        cin >> a[i].s >> a[i].e >> a[i].c;
    }
    int maxR = 0, maxRCost = inf;
    int minL = inf, maxLCost = inf;
    int maxLen = 0, maxLenCost = inf;
    for(int i = 0;i<n;++i){
        int l = a[i].s, r = a[i].e, c = a[i].c;
        if(l <  minL){
            minL = l;
            maxLCost = inf;
        }
        if(l == minL)maxLCost = min(maxLCost, c);

        if(r > maxR){
            maxR = r;
            maxRCost = inf;
        }
        if(r == maxR){
            maxRCost = min(maxRCost, c);
        }
        if(maxLen < r-l+1){
            maxLen = r-l+1;
            maxLenCost = inf;
        }
        if(maxLen == r-l+1)maxLenCost = min(maxLenCost, c);
        int ans = maxRCost+maxLCost;
        if(maxLen == maxR - minL+1){
            ans = min(ans, maxLenCost);
        }
        cout << ans << endl;
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
    while (T--)
    {
        solve();
    }
}