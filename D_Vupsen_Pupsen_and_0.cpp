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
long long gcd(long long a, long long b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    for(int i = 0;i<n;++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    vector<int>res(n);

    int s1 = 0, s2 = 0;
    vector<int>pref(n);
    pref[0] = a[0].first;
    for(int i = 1;i<n;++i){
        pref[i]=pref[i-1]+a[i].first;
    }


    int fi = 0;
    int min_lcm = 1e18;
    for(int i = 0;i<n-1;++i){
        if(pref[i] != 0 && (pref[n-1]-pref[i]) !=0){
            int l = lcm(pref[i], pref[n-1]-pref[i]);
            if(l < min_lcm){
                min_lcm = l;
                s1 = pref[i];
                s2 = pref[n-1]-pref[i];
                fi = i;
            }
        }
    }

    int l = lcm(s1, s2);
    int times_one = (l/s1), times_two = -(l/s2);

    for(int i = 0;i<=fi;++i)res[a[i].second] = times_one;
    for(int i = fi+1;i<n;++i)res[a[i].second] = times_two;

    for(auto x : res)cout << x << ' ';
    cout << endl;
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