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

vector<int>compute(vector<int>&a){
    int n = a.size();
    vector<int>pref(n);
    pref[0] = a[0];
    for(int i = 1;i<n;++i){
        pref[i] = pref[i-1]+a[i];
    }
    return pref;
}

void solve()
{
    int n,k;
    cin >> n >> k;
    k--;
    vector<int>a(n);
    for(int &u : a)cin>> u;
    priority_queue<int>pq;
    vector<int>p=compute(a);
    int res = 0;
    int og = p[k];
    for(int i = k;i>=0;--i){
        if(p[i] < p[k]){
            while(!pq.empty()){
                int u = pq.top();
                pq.pop();
                p[k]-=(2*u);
                res++;
                if(p[k] <= p[i])break;
            }
            
        }
        pq.push(a[i]);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>x;
    int add = 0;
    for(int i = k+1;i<n;++i){
        x.push({a[i],i});
        p[i]+=add;
        if(p[i] < og){
            while(!x.empty()){
                int u = x.top().first;
                int idx = x.top().second;
                x.pop();
                p[i]+=abs(u*2);
                add+=abs(u*2);
                res++;
                if(og<=p[i])break;
            }
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}