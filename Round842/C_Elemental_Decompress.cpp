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
    vector<pair<int,int>>a(n+1);
    map<int,int>freq;
    vector<int>k(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i].first, a[i].second = i;
    for(int i = 1;i<=n;++i)k[i] = a[i].first;
    sort(all(a));
    vector<int>b(n+1),c(n+1);
    multiset<int>bb,cc;
    for(int i = 1;i<=n;++i)bb.insert(i),cc.insert(i);
    for(int i =1;i<=n;++i)freq[a[i].first]++;
    map<int,int>taken;
    for(int i = 1;i<=n;++i){
        if(freq[a[i].first]>2){
            cout<< "NO" << endl;
            return;
        }
        
        if(freq[a[i].first]==2){
            if(taken[a[i].first]==0)b[a[i].second] = a[i].first;
            else c[a[i].second] = a[i].first;
            bb.erase(a[i].first);
            cc.erase(a[i].first);
        }else{
            if(bb.count(a[i].first)){
                b[a[i].second] = a[i].first;
                bb.erase(a[i].first);
            }else{
                c[a[i].second] = a[i].first;
                cc.erase(a[i].first);
            }
        }
        taken[a[i].first]++;
    }
    reverse(all(a));
    for(int i = n;i>=0;--i){
        if(a[i].second==0)continue;
        if(b[a[i].second]==0){
            b[a[i].second] = *bb.begin();
            bb.erase(bb.begin());
        }else{
            c[a[i].second] = *cc.begin();
            cc.erase(cc.begin());
        }
    }
    for(int i =1;i<=n;++i){
        if(max(b[i],c[i])!=k[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for(int i = 1;i<=n;++i)cout << b[i] << ' ';
    cout << endl;
    for(int i = 1;i<=n;++i)cout << c[i] << ' ';
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