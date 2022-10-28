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
    vector<int>a(n+2);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<int>b={0};
    int sum = 0;
    for(int i = 1;i<k;++i){
        if(a[i] >= 0 && a[i-1] < 0){
            if(sum!=0)b.pb(sum);
            sum = 0;
        }else if(a[i] < 0 && a[i-1] >= 0){
            if(sum!=0)b.pb(sum);
            sum = 0;
        }
        sum+=a[i];
    }
    if(sum!=0)b.pb(sum);
    int nk = b.size();
    b.pb(a[k]);
    sum = 0;
    for(int i = k+1;i<=n;++i){
        if(a[i] >= 0 && a[i-1] < 0){
            if(sum!=0)b.pb(sum);
            sum = 0;
        }else if(a[i] < 0 && a[i-1] >= 0){
            if(sum!=0)b.pb(sum);
            sum = 0;
        }
        sum+=a[i];
    }
    if(sum!=0)b.pb(sum);
    n = b.size()-1;
    

    int l = nk-1, r = nk+1;
    int m = 1;
    int curr = b[nk];
    vector<int>re;
    while(1){
        if(m){
            bool ok = 0;
            for(int i = r;i<=n;++i){
                if(curr+b[i] >= 0){curr+=b[i];ok = 1;r=i+1;}
                else{
                    break;
                }
            }
            re.pb(ok);
        }else{
            bool ok = 0;
            for(int i = l;i>=1;--i){
                if(curr+b[i]>=0){curr+=b[i];ok = 1;l=i-1;}
                else{
                    break;
                }
            }
            re.pb(ok);
        }
        if(r>n || l < 1){
            cout << "YES" << endl;
            return;
        }
        if(re.size() >= 2){
            if(!re.back() && !re[(int)(re.size())-2]){
                break;
            }
        }
        m= !m;
    }
    l = nk-1;
    r = nk+1;
    curr = b[nk];
    m = 0;
    re.clear();
    while(1){
        if(m){
            bool ok = 0;
            for(int i = r;i<=n;++i){
                if(curr+b[i] >= 0){curr+=b[i];ok = 1;r=i+1;}
                else{
                    break;
                }
            }
            re.pb(ok);
        }else{
            bool ok = 0;
            for(int i = l;i>=1;--i){
                if(curr+b[i]>=0){curr+=b[i];ok = 1;l=i-1;}
                else{
                    break;
                }
            }
            re.pb(ok);
        }
        if(r>n || l < 1){
            cout << "YES" << endl;
            return;
        }
        if(re.size() >= 2){
            if(!re.back() && !re[(int)(re.size())-2]){
                break;
            }
        }
        m= !m;
    }
    cout << "NO" << endl;
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