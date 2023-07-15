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
    vector<string>a(2);
    cin >> a[0] >> a[1];
    a[0] = "0"+a[0];
    a[1] = "0"+a[1];
    int t,q;
    cin >> t >> q;
    set<int>no;
    int time = 1;
    for(int i = 1;i<a[0].size();++i){
        if(a[0][i] != a[1][i])no.insert(i);
    }
    vector<int>val(q+1,-1);
    for(int j= 0;j<q;++j){
        int type;
        cin >> type;
        if(val[time]!=-1){
            int p = val[time];
            if(a[1][p]!=a[0][p])no.insert(p);
            else{
                if(no.count(p))no.erase(p);
            } 
        }
        if(type==2){
            int c1,p1,c2,p2;
            cin >> c1 >> p1 >> c2 >> p2;
            c1--;
            c2--;
            swap(a[c1][p1],a[c2][p2]);
            if(a[1-c1][p1]!=a[c1][p1])no.insert(p1);
            else{
                if(no.count(p1))no.erase(p1);
            } 
            
            if(a[1-c2][p2]!=a[c2][p2])no.insert(p2);
            else{
                if(no.count(p2))no.erase(p2);
            } 
        }else if(type==3){
            if(no.empty())cout << "YES" << endl;
            else cout << "NO" << endl;
        }else{
            int p;
            cin >> p;
            if(no.count(p))no.erase(p);
            if((time+t) <= q)val[time+t] = p;
        }
        time++;
    }
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