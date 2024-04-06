#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
// #define endl "\n"

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
    int n,x,y;
    cin >>n >>x >> y;
    vector<pair<int,int>>a(n+1);
    for(int i= 1;i<=n;++i)cin >> a[i].first >> a[i].second;
    set<int>gr1,gr2;
    for(int i = 1;i<=n;++i){
        bool x1 = a[i].first%2, x2 = a[i].second%2;
        if((x1==0 && x2==0) || (x1==1 && x2==1))gr1.insert(i);
        else gr2.insert(i);
    }
    bool x1 = x%2, x2 = y%2;
    if((x1==0 && x2==0) || (x1==1 && x2==1)){}
    else swap(gr1,gr2);

    if(gr1.size() >= gr2.size()){
        cout << "First" << endl;
        for(int i = 1;i<=n;++i){
            if(gr1.empty() && gr2.empty())break;
            if(gr2.size() > 0){
                cout<<*gr2.begin() << endl;
                gr2.erase(gr2.begin());
            }else{
                cout << *gr1.begin() << endl;
                gr1.erase(gr1.begin());
            }
            if(gr1.empty() && gr2.empty())break;

            int x;cin >> x;
            if(gr1.count(x))gr1.erase(x);
            else gr2.erase(x);
        }
    }else{
        cout << "Second" << endl;
        for(int i = 1;i<=n;++i){
            if(gr1.empty() && gr2.empty())break;
            int x;cin >> x;
            if(gr1.count(x))gr1.erase(x);
            else gr2.erase(x);

            if(gr1.empty() && gr2.empty())break;

            if(gr1.size() > 0){
                cout << *gr1.begin() << endl;
                gr1.erase(gr1.begin());

            }else{
                cout<<*gr2.begin() << endl;
                gr2.erase(gr2.begin());
            }
        }
    }

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