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

int time(int a, int b, int x){
    // time to reach x

    if(a>=x)return 1;
    return (x-b+a-b-1)/(a-b);
}

void solve()
{
    int q;
    cin >> q;
    int l = 0, r = 0;
    int got = -1;
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int a,b,n;
            cin >> a >> b >> n;
            int h = 0, m = 0;
            if(n==1){
                m = 1;
                h = a;
            }else{
                h = (a*n)-(b*(n-1));
                m = h-a+b+1;
            }
            if(got==-1){
                got = 1;
                l = m;
                r = h;
                cout << 1 << ' ';
            }else{
                // check if [m,h] interesects [l,r]
                if((m>=l && m<=r) || (h>=l && h <= r) || (l>=m && l<=h) || (r>=m && r<=h)){
                    l = max(l,m);
                    r = min(r,h);
                    cout << 1 << ' ';
                }else{
                    cout << 0 << ' ';
                }
            }
        }else{
            int a,b;
            cin >> a >> b;
            if(got==-1){
                cout << -1 << ' ';
                continue;
            }
            int t1 = time(a,b,l),t2=time(a,b,r);
            if(t1==t2)cout <<t1 << ' ';
            else cout << -1 << ' ';
        }
    }
    cout << endl;
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