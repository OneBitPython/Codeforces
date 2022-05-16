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


bool ok(string s,  vector<int>&prefix, vector<int>&pos, int x, int tot){
    int n = pos.size();
    if(x>=n)return 1;
    // have to leave x zeroes remaining
    for(int i = 0;i<n;++i){
        if(i+x > n)break;
        int c1 = 0, c2 = 0;
        if(i > 0){
            c1 = prefix[pos[i-1]];
        }
        if(i+x < n)c2 = tot- prefix[pos[i+x]];
        if(c1 + c2<=x)return 1;
    }

    return 0;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int>prefix(n);
    int cnt = 0;
    vector<int>pos;
    for(int i = 0;i<n;++i){
        if(s[i] == '0')pos.pb(i);
        else cnt++;
        prefix[i] = cnt;
    }
    int tot = count(all(s), '1');
    cnt = count(all(s), '0');
    for(int i = 0;i<n;++i){
        if(s[i]=='0')cnt--;
        else break;
    }
    for(int i = n-1;i>=0;--i){
        if(s[i] == '0')cnt--;
        else break;
    }
    if(cnt<=0){
        cout << 0 << endl;
        return;
    }
    int l = -1, r = 1e18;
    while(l+1 < r){
        int m = (l+r)/2;
        if(ok(s,prefix,pos,m,tot))r = m;
        else l = m;
    }
    cout << r << endl; 
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
        solve();
    }
}