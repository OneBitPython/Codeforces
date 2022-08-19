#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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
    vector<vector<int>>a(2, vector<int>(n));
    for(int i = 0;i<2;++i){
        for(int j = 0;j<n;++j)cin >> a[i][j];
    }
    vector<pair<int,int>>suff1(n), suff2(n), suff3(n), suff4(n);
    suff1.back() = {a[0].back()-(n-1), n-1};
    suff2.back() = {a[1].back()-(n-1), n-1};
    for(int i = n-2;i>=0;--i){
        int val = a[0][i] - i;
        int v2 = a[1][i] - i;
        if(val > suff1[i+1].first){
            suff1[i] = {val, i};
        }else suff1[i] = suff1[i+1];

        if(v2 > suff2[i+1].first){
            suff2[i] = {v2, i};
        }else suff2[i] = suff2[i+1];


    }
    dbg(suff1, suff2);
    int res = 1e18;
    int r = 0, c = 0;
    int time = 0;
    int m = 1;
    int visited = 0;
    while(1){
        if(visited == 2*n)break;
        visited++;
        if(r == 0 && c == 0){}
        else time = max(time, a[r][c]+1);

        if(r == 0){
            int reach = time;
            int mx,dist1;
            if(c < n-1){
                mx = a[0][suff1[c+1].second];
                dist1 = suff1[c+1].second - c;
                reach = max(time+dist1, mx+1);
                
                reach+=(n-suff1[c+1].second-1);
                
            }else reach++;
            if(visited%2==1){
                mx = a[1][suff2[c].second];
                dist1 = n-suff2[c].second;
                reach = max(reach+dist1, mx+1);
                reach+=(suff2[c].second-c);
                res = min(res, reach);
            }else if(c < n-1){
                mx = a[1][suff2[c+1].second];
                dist1 = n - suff2[c+1].second;
                reach = max(reach + dist1, mx + 1);
                reach += (suff2[c+1].second - c);
                res = min(res, reach);
            }
            dbg(res);
        }else{
            int reach = time;
            int mx, dist1;
            if(c < n-1){
                mx = a[1][suff2[c+1].second];
                dist1 = suff2[c+1].second - c;
                reach = max(time+dist1, mx+1);
                reach+=(n-suff2[c+1].second-1);
                
            }else reach++;
            if(visited%2==1){
                mx = a[0][suff1[c].second];
                dist1 = n - suff1[c].second;
                reach = max(reach + dist1, mx + 1);
                reach += (suff1[c].second - c);
                res = min(res, reach);
            }else if(c < n-1){
                mx = a[0][suff1[c+1].second];

                dist1 = n - suff1[c+1].second;
                reach = max(reach + dist1, mx + 1);
                reach += (suff1[c+1].second - c);
                res = min(res, reach);
            }
            
        }

        if(m == 1)r++;
        else if(m == 2)c++;
        else if(m == 3)r--;
        else if(m == 4)c++;
        m++;
        time++;
        if(m > 4)m = 1;
    }
    dbg(time-1);
    res = min(res, time-1);
    cout << res << endl;
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