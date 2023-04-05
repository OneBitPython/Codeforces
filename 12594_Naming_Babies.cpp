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

/*
pref1 stores the prefix sum of -pos*pos for each i
pref2 store the prefix sum of i*pos[s[i]]
pref3 stores the prefix sum of pos[s[i]]
*/
vector<int>pref1,pref2,pref3;
const int N = 20001,K=501;
int dp[N][2];

int sum(int i, int j,vector<int>&pr){
    return pr[j]-pr[i-1];
}

int cost(int i, int j){
    int res = sum(i,j,pref1);
    res+=sum(i,j,pref2);
    res-=((i-1)*sum(i,j,pref3));
    return res;
}
void dnc(int j, int l, int r, int optl,int optr){
    if(l > r)return;
    int m = (l+r)/2;
    pair<int,int>best = {1e18,0};
    for(int i = optl;i<min(m,optr+1);++i){
        best= min(best, {dp[i][j^1]+cost(i+1,m),i});
    }
    dp[m][j] = best.first;
    int opt = best.second;
    dnc(j,l,m-1,optl,opt);
    dnc(j,m+1,r,opt,optr);
}

void solve()
{
    string p;
    int k;
    string s;
    cin >> p >> k >> s;
    int n = s.size();
    pref1 = vector<int>(n+1);
    pref2 = vector<int>(n+1);
    pref3 = vector<int>(n+1);
    s = "0"+s;
    for(int i = 1;i<=n;++i){
        int pos = 0;
        for(int j = 0;j<(int)(p.size());++j){
            if(p[j]==s[i])pos = j;
        }
        pref1[i] = pref1[i-1]+(-pos*pos);
        pref2[i] = pref2[i-1]+(i-1)*pos;
        pref3[i] = pref3[i-1]+pos;
    }
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=1;++j)dp[i][j] = 1e18;
    }
    dp[0][0] = 0;
    for(int j = 1;j<=k;++j)dnc(j%2,1,n,0,n-1);
    cout << dp[n][k%2] << endl;
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
        cout << "Case " << i << ": ";
        solve();
    }
}