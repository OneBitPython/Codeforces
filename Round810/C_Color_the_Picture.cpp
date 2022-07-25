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

bool oddcols(int n,int m, vector<int>&a, int k){
    int res = 0;
    int odd = 0;
    // you should take atleast one row with odd number of values
    vector<int>cols;
    for(int i = 0;i<k;++i){
        int x = a[i]/n;
        if(x <= 1)continue;
        if(x%2)odd++;
        cols.pb(x);
        res+=x; 
    }
    bool ok = 0;
    if(odd  == 0){
        for(int i = 0;i<cols.size();++i){
            if(cols[i] > 2){
                res--;
                odd = 1;
                ok = 1;
                break;
            }
        }
    }else ok = 1;
    if(odd%2 == 0){
        res--;
    }
    if(res>=m && ok)return 1;
    return 0;
}


bool evencols(int n,int m, vector<int>&a, int k){
    int taken = 0;
    int odd = 0;
    for(int i = 0;i<k;++i){
        // you need some even number * n colors
        int x = a[i]/n;
        if(x<=1)continue;
        if(x%2)odd++;
        taken+=x;
    }
    // even number of odd rows has to be there
    if(odd%2 == 1){
        taken--;
    }
    if(taken >= m)return 1;
    return 0;
}

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int>a(k);
    for(int &u : a)cin >> u;
    bool ok = 0;
    if(m%2)ok|=(oddcols(n,m,a,k));
    else ok|=(evencols(n,m,a,k));

    swap(n,m);
    if(m%2)ok|=(oddcols(n,m,a,k));
    else ok|=(evencols(n,m,a,k));
    cout << (ok?"Yes":"No") << endl;
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