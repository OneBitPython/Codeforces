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
    int n;
    cin >> n;
    vector<vector<int>>a(n+1);
    for(int i = 1;i<=n;++i){
        int c;
        cin >> c;
        a[i].resize(c+1);
        for(int j = 1;j<=c;++j)cin >> a[i][j];
    }
    set<vector<int>>st;
    int m;
    cin >> m;
    for(int i = 1;i <= m;++i){
        vector<int>d(n+1);
        for(int j = 1;j<=n;++j)cin >> d[j];
        st.insert(d);
    }

    priority_queue<pair<int,vector<int>>>pq;
    vector<int>best(n+1);
    int c = 0;
    for(int i = 1;i<=n;++i)best[i] = (int)(a[i].size())-1,c+=a[i].back();
    pq.push({c, best});
    map<vector<int>,bool>vis;
    while(1){
        pair<int,vector<int>>b = pq.top();
        pq.pop();

        if(st.count(b.second)==0){
            for(int j = 1;j<=n;++j)cout << b.second[j] << ' ';
            cout << endl;
            return;
        }
        for(int j = 1;j<=n;++j){
            if(b.second[j] == 1)continue;
            int val = a[j][b.second[j]-1];
            b.second[j]--;
            if(!vis[b.second]){
                pq.push({b.first+val-a[j][b.second[j]+1], b.second});
                vis[b.second]= 1;
            }
            b.second[j]++;
        }
    }
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