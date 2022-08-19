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
    vector<int>a(n);
    /*
    every cycle of digits eventually goes to an 8 except 5 and 0. So we can just try to apply one opeation on every value ending with 5 and check if the set becomes equal
    1->2->4->8
    2->4->8
    3->6->2->4->8
    4->8
    ...
    */
    for(int i = 0;i<n;++i){
        cin >> a[i];
    }
    int s = *max_element(all(a));
    while((s%10)!=8){
        s+=(s%10);
    }
    set<int>moves;
    int cnt = 0;
    for(auto x : a){
        if((x%10) == 0 || (x%10) == 5){
            cnt++;
            continue;
        }
        int ops = 0;
        while((x%10)!=8){
            x+=(x%10);
            ops++;
        }   
        moves.insert(ops);
    }
    if(cnt < n && cnt > 0){
        cout << "No" << endl;
        return;
    }
    if(cnt == n){
        set<int>vals;
        for(auto x : a){
            vals.insert(x+(x%10));
        }
        if(vals.size() == 1)cout << "Yes" << endl;
        else cout << "No" << endl;
        return;
    }
    if(moves.size() == 1){
        cout << "Yes" << endl;
    }else cout << "No" << endl;
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