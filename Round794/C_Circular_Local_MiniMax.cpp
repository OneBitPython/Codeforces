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

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}


int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n){
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        val+="1";
      }
      else
      {
        val+="0";
      }
    }
    while(val.front()=='0'){
        val.erase(0,1);
    }
    return val;
}


bool check(vector<int>&a){
    int n = a.size();
    bool ok = 0;
    for(int i = 1;i<n-1;++i){
        if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])){

        }else return 0;
    }
    if((a[n-1] > a[n-2] && a[n-1] > a[0]) || (a[n-1]<a[n-2] && a[n-1]<a[0])){

    }else return 0;
    if((a[0] > a[n-1] && a[0] > a[1]) || (a[0] < a[n-1] && a[0] < a[1])){
        
    }else return 0;
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    sort(all(a));
    // start with greatest element
    int pos_min = (n/2)-1;
    int pos_max = n-1;
    vector<int>res(n);
    bool curr = 1;
    for(int i = 0;i<n;++i){
        if(curr){res[i] = a[pos_max];pos_max--;}
        else{
            res[i] = a[pos_min];
            pos_min--;
        }
        curr =!curr;
    }
    if(check(res)){
        cout << "YES" << endl;
        for(auto x : res)cout << x << ' ';
        cout << endl;
        return;
    }
    // start with least element
    
    if(n%2){
        pos_min = n/2;
    }else pos_min = (n/2)-1;
    pos_max = n-1;
    res.clear();
    res.resize(n);
    curr = 0;
    for(int i = 0;i<n;++i){
        if(curr){res[i] = a[pos_max];pos_max--;}
        else{
            res[i] = a[pos_min];
            pos_min--;
        }
        curr = !curr;
    }
    if(check(res)){
        cout << "YES" << endl;
        for(auto x : res)cout << x << ' ';
        cout << endl;
        return;
    }
    cout << "NO" << endl;
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