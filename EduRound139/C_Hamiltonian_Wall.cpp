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

bool pos(int i, int j, vector<vector<int>>&a){
    queue<pair<int,int>>q;
    q.push({i,j});
    int n = a[0].size();
    vector<vector<int>>visited(2, vector<int>(n));
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        if(visited[i][j] || !a[i][j])continue;
        visited[i][j] = 1;
        if(i==0){
            if(a[i+1][j] && !visited[i+1][j])q.push({i+1,j});
            else{
                if(j < n-1)q.push({i,j+1});
            }
        }else if(i==1){
            if(a[i-1][j] && !visited[i-1][j])q.push({i-1,j});
            else{
                if(j < n-1)q.push({i,j+1});
            }
        }
    }
    bool ok = 1;
    for(int i = 0;i<2;++i){
        for(int j = 0;j<n;++j){
            if(a[i][j] && !visited[i][j])ok = 0;
        }
    }
    return ok;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>a(2, vector<int>(n));
    int cnt = 0;
    queue<pair<int,int>>q;
    for(int i = 0;i<2;++i){
        string s;
        cin >> s;
        for(int j = 0;j<n;++j){
            if(s[j]=='B')a[i][j] = 1;
        }
    }
    for(int j = 0;j<n;++j){
        if(a[0][j] || a[1][j]){
            if(a[0][j] && pos(0,j,a)){
                cout << "YES" << endl;
                return;
            }
            if(a[1][j] && pos(1,j,a)){
                cout << "YES" << endl;
                return;
            }
            break;
        }
    }
    
    cout << ("NO") << endl;
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