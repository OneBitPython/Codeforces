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
    vector<pair<int,int>>a(n);
    for(int i = 0;i<n;++i){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    int mx = 2.6e6;
    if(n<=10000){
        map<int,pair<int,int>>sum;
        for(int i = 0;i<n;++i){
            for(int j = i+1;j<n;++j){
                if(sum.count(a[i].first+a[j].first)){
                    
                    int k = sum[a[i].first+a[j].first].first, l = sum[a[i].first+a[j].first].second;
                    if(i!=k && i!=l && j!=k && j!=l){
                        cout << "YES" << endl;
                        cout << i+1 << ' ' << j+1 << ' ' << k+1 << ' ' << l+1 << endl;
                        return;
                    }
                }
                sum[a[i].first+a[j].first] = {i,j};
            }
        }
        cout << "NO" << endl;
        return;
    }
    sort(all(a));
    int l = 0, r = n-1;
    while(l < r){
        if(l+1 >= r-1)break;
        int left = a[l].first+a[r].first;
        int right = a[l+1].first + a[r-1].first;
        if(left < right)l++;
        else if(left > right)r--;
        else{
            cout << "YES" << endl;
            cout << a[l].second << ' ' << a[r].second << ' ' << a[l+1].second << ' ' << a[r-1].second << endl;
            return;
        }
    }
    cout << "NO" << endl;
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