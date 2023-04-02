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
    int n,m;
    cin >> n >> m;
    vector<int>a(n+1);
    for(int i = 1;i<n;++i)cin >> a[i];
    vector<vector<int>>b(n+1, vector<int>(m+1)),c(n+1, vector<int>(m+1));

    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j)cin >> b[i][j];
    }
    // let c[i][j] denote the next restaurant k such that b[k][j] > b[i][j]. can compute in nm time
    for(int j = 1;j<=m;++j){
        stack<int>st;
        for(int i = n;i>=1;--i){
            while(!st.empty() && b[i][j]>=b[st.top()][j])st.pop();
            if(st.empty())c[i][j]=-1;
            else c[i][j]=st.top();
            st.push(i);
        }
    }

    vector<int>inc(n+1);
    vector<vector<int>>taken(n+1, vector<int>(m+1));
    
    int res = 0;
    for(int i = 1;i<=n;++i){
        int ans = 0;
        for(int j = 1;j<=m;++j){
            ans+=b[i][j];
            int x = i;
            while(!taken[x][j]){
                int k = c[x][j];
                if(k==-1)break;
                inc[k]+=(b[k][j]-b[x][j]);
                taken[x][j] = 1;
                x = c[x][j];
            }
        }
        res = max(res,ans);
        for(int j = i+1;j<=n;++j){
            ans-=a[j-1];
            ans+=inc[j];
            res = max(res, ans);
        }
        for(int j = 1;j<=m;++j){
            int k = c[i][j];
            if(k!=-1)inc[k]-=b[k][j]-b[i][j];
        }
    }
    cout << res << endl;
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