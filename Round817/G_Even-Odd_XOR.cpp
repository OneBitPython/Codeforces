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

// https://www.geeksforgeeks.org/find-n-distinct-numbers-whose-bitwise-xor-is-equal-to-k/


vector<int> f(int N, int K,int c)
{
     
    // Base Cases
    vector<int>res;
    if (N == 1)
    {
        res.pb(K);
        return res;
    }

    if (N == 2)
    {
        res.pb(0);
        res.pb(K);
        return res;
    }

    // Assign values to P and Q
    int P = N - 2;
    int Q = N - 1;
 
    // Stores Bitwise XOR of the
    // first (N - 3) elements
    int VAL = 0;
 
    // Print the first N - 3 elements
    for(int i =1;i<=N-3;++i){res.pb(i);VAL^=i;}
 
    if (VAL == K)
    { // checking whether P ^ Q is greater than P or not.   
      while( (P ^ Q) <= P)
            {    Q++;
            }
        res.pb(P);
        res.pb(Q);
        res.pb(P^Q);
    }
 
    else
    { // checking whether P ^ K ^ VAL is greater than N-2 or not.
  
      while( (P ^ K ^ VAL) <= N-3)
        {    P++;
        }
        res.pb(0);
        res.pb(P);
        res.pb(P^K^VAL);
    }
    return res;
}


void solve()
{
    int n;
    cin >> n;
    vector<int>r1;
    for(int n = 3;n<=100;++n){
        int c = n+(1ll<<30);
        int K = 0;
        for(int j = 0;j<(n+1)/2;++j){
            r1.pb(c);
            K^=r1.back();
            c++;
        }


        vector<int>r2 = f(n/2,K,0);
        vector<int>s;
        for(int i = 0;i<r2.size();++i){s.pb(r1[i]);s.pb(r2[i]);}
        if(n%2)s.pb(r1.back());
        set<int>g(all(s));
        dbg(n,g.size());
        assert(g.size() == n);
        // for(auto x : s)cout << x << ' ';
        // cout << endl;
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    srand(time(0));
    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}