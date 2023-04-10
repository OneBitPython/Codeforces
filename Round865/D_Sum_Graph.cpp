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


int query(int i, int j){
    cout << "? " << i << ' ' << j << endl;
    int k;
    cin >> k;
    return k;
}
int common(vector<int>a,vector<int>b){
    for(auto x : a){
        for(auto y : b){
            if(x==y)return x;
        }
    }
    return 0;
}
void solve()
{
    int n;
    cin >> n;
    if(n==2){
        cout << "! 1 2 2 1" << endl;
        int k;
        cin >> k;
        return;
    }
    cout << "+ " << n+1 << endl;
    int k;
    cin >> k;
    cout << "+ " << n+2 << endl;
    cin >> k;
    vector<int>d1(n+1),d2(n+1);
    for(int i = 2;i<=n;++i){
        d1[i] = query(1,i);
    }
    for(int i= 1;i<=n;++i){
        if(i==2)continue;
        d2[i] = query(2,i);
    }
    vector<int>res1(n+1),res2(n+1);
    vector<int>b(n+1),pos(n+1);
    int c = 1;
    for(int i = 1;i<=n;i+=2)b[i] = c,pos[c]=i,c++;
    c = n;
    for(int i = 2;i<=n;i+=2)b[i]=c,pos[c]=i,c--;
    int val = *max_element(all(d1)),val2 = *max_element(all(d2));
    res1[1] = b[val+1];

    vector<int>w = {val+1+d1[2],val+1-d1[2]};
    for(auto x : w){
        if(val2+1==x || (n-val2)==x){
            res1[2] = b[x];
            break;
        }
    }
    if(n%2 && val == (n/2))res1[2] = b[val+1+d1[2]];

    for(int i = 3;i<=n;++i){
        vector<int>d,e;
        if(pos[res1[1]]+d1[i]<=n)d.pb(pos[res1[1]]+d1[i]);
        if(pos[res1[1]]-d1[i]>=1)d.pb(pos[res1[1]]-d1[i]);
        if(pos[res1[2]]+d2[i]<=n)e.pb(pos[res1[2]]+d2[i]);
        if(pos[res1[2]]-d2[i]>=1)e.pb(pos[res1[2]]-d2[i]);
        res1[i] = b[common(d,e)];
    }
    res2[1] = b[n-val];
    w = {n-val+d1[2],n-val-d1[2]};
    for(auto x : w){
        if(val2+1==x || (n-val2)==x){
            res2[2] = b[x];
            break;
        }
    }
    if(n%2 && val == (n/2))res2[2] = b[val+1-d2[1]];

    for(int i = 3;i<=n;++i){
        vector<int>d,e;
        if(pos[res2[1]]+d1[i]<=n)d.pb(pos[res2[1]]+d1[i]);
        if(pos[res2[1]]-d1[i]>=1)d.pb(pos[res2[1]]-d1[i]);
        if(pos[res2[2]]+d2[i]<=n)e.pb(pos[res2[2]]+d2[i]);
        if(pos[res2[2]]-d2[i]>=1)e.pb(pos[res2[2]]-d2[i]);
        res2[i] = b[common(d,e)];
    }
    cout << "! ";
    for(int i =1;i<=n;++i)cout << res1[i] << ' ';
    for(int i =1 ;i<=n;++i)cout << res2[i] << ' ';
    cout << endl;
    cin >> k;
}   

int32_t main()
{

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

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