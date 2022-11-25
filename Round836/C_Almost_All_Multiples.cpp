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

const int mxn = 1e5+5;
vector<bool>isprime(mxn+5);
void pre(){
    isprime[0] = isprime[1] = 0;
    for(int i = 1;i*i<=mxn;++i){
        if(isprime[i]){
            for(int j = i*i;j<=mxn;++j)isprime[j] = 0;
        }
    }
}

void solve()
{
    int n,x;
    cin >> n >> x;
    if(x==n){
        cout << x << ' ';
        for(int i = 2;i<n;++i)cout << i << ' ';
        cout << 1 << ' ';
        cout << endl;
        return;
    }
    if(isprime[n]){
        cout << -1 << endl;
        return;
    }
    vector<int>res(n+1,-1);
    res[1] = x;
    res.back() = 1;
    if((n%x) != 0){
        cout << -1 << endl;
        return;
    }
    vector<int>taken(n+1);
    taken[x] = taken[1] = 1;
    for(int i = x*2;i<=n;i+=x){
        if(n%i == 0 && !taken[i]){
            int choose = i;
            bool done = 0;
            while(1){
                if(x==n)break;
                res[x] = choose;
                taken[choose] = 1;
                x = choose;
                done = 1;
                // some multiple of choose that is divisible by n
                bool got = 0;
                for(int multiple = choose*2;multiple<=n;multiple+=choose){
                    if((n%multiple)==0 && !taken[multiple]){
                        choose = multiple;
                        got = 1;
                        break;
                    }
                }
                if(!got)break;
                // if((n/x)%2){
                //     if(x!=n)res[x] = n;
                //     break;
                // }
                // choose*=2;
            }
            if(done)break;
        }
    }
    for(int i = 2;i<=n;++i){
        if(res[i]==-1)res[i] = i;
    }
    for(int i = 1;i<n;++i){
        if((res[i]%i)!=0){
            cout << -1 << endl;
            return;
        } 
    }
    for(int i = 1;i<=n;++i)cout << res[i] << ' ';
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
    // #endif

    int T=1;
    cin >> T;
    pre();
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}