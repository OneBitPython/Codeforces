#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

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
    int x;
    cin >> x;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    int r = 0;
    string s(n, '0');
    for(int i = n-1;i>=0;--i){
        if(a[i] > r){
            if(r < x){
                r++;
                s[i] = '1';
            }
        }else{
            s[i] = '1';
        }
    }
    cout << s << endl;
    // string s(n, '0');
    // ordered_set b;
    // for(int i = n-1;i>=0;--i)b.insert(a[i]);
    // for(int i = 0;i<n;++i){
    //     b.erase(find(all(b), a[i]));
    //     if(a[i] <= x){
    //         s[i] = '1';
    //         continue;
    //     }
    //     int ogl = 0, newl = 0;

    //     if(!b.empty()){
    //         int mn = *b.begin();
            
    //         if(x+1 > mn )ogl = b.order_of_key (x+1);
    //         if(x > mn)newl = b.order_of_key(x);
    //     }
    //     if(ogl == newl && x > 0){
    //         x--;
    //         s[i] = '1';
    //     }
    // }
    // cout << s << endl;
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