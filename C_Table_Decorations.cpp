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

int f(int x,vector<int>a){
    a[0]-=(2*x);
    a[1]-=((x+1)/2);
    a[2]-=(x/2);
    // if(a[0]<0 || a[1] < 0 || a[2]<0)return -1e9;
    return *max_element(all(a))-*min_element(all(a));
}
int f2(int x,vector<int>a){
    a[0]-=(2*x);
    a[1]-=x;
    sort(all(a),greater<int>());
    return a[1]-a[2];
}
int f3(int x,vector<int>a){
    int y = x/2;
    a[0]-=(y*3);
    a[1]-=(y*3);
    int rem = x%2;
    if(rem && a[0]>a[1]){
        a[0]-=2;
        a[1]--;
    }else a[0]--,a[1]-=2;
    sort(all(a),greater<int>());
    return *max_element(all(a))-*min_element(all(a));
}
int first_case(vector<int>a){
    sort(all(a),greater<int>());
    int res = 0;
    if(a[0]-a[2] <= 1)res = (a[0]+a[1]+a[2])/3;
    return res;
}
int second_case(vector<int>a){
    // 2nd case - when the difference between the second and third value is <= 1 and the first value is much greater
    sort(all(a),greater<int>());
    int l = 0, r = min({a[0]/2,a[1]*2,a[2]*2+1});
    while(l + 2 < r){
        int m1 = l+((r-l)/3);
        int m2 = r-((r-l)/3);
        if(f(m1,a) < f(m2,a))r = m2;
        else l = m1;
    }
    int res = 0;
    int mn = 1e18;
    for(int i = l;i<=r;++i){
        if(f(i,a)<=mn){
            res = i;
            mn = f(i,a);
        }
    }
    int x = res;
    a[0]-=(2*x);
    a[1]-=((x+1)/2);
    a[2]-=(x/2);
    return first_case(a) + res;
}

int third_case(vector<int>a){
    // 3rd case, all values are far apart, so bring the highest value closer to the other two values
    sort(all(a),greater<int>());

    int l = 0, r = min({a[0]/2,a[1]});
    while(l+2 < r){
        int m1 = l+((r-l)/3);
        int m2 = r-((r-l)/3);
        if(f2(m1,a) < f2(m2,a))r = m2;
        else l = m1;
    }
    int mn = 1e18;
    int res = 0;
    for(int i = l;i<=r;++i){
        if(f2(i,a)<=mn){
            res = i;
            mn = f2(i,a);
        }
    }
    a[0]-=(2*res);
    a[1]-=res;
    sort(all(a),greater<int>());
    return second_case(a)+res;
    return 0;
}

int fourth_case(vector<int>a){
    sort(all(a),greater<int>());

    int l = 0, r= min(a[0]/3 * 2,a[1]/3 * 2);
    while(l+2 < r){
        int m1 = l+((r-l)/3);
        int m2 = r-((r-l)/3);
        if(f3(m1,a) < f3(m2,a))r = m2;
        else l = m1;
    }
    
    int mn = 1e18;
    int res = 0;
    for(int i = l;i<=r;++i){
        if(f3(i,a)<=mn){
            mn= f3(i,a);
            res = i;
        }
    }
    int x= res;
    int y = x/2;
    a[0]-=(y*3);
    a[1]-=(y*3);
    int rem = x%2;
    if(rem && a[0]>a[1]){
        a[0]-=2;
        a[1]--;
    }else a[0]--,a[1]-=2;
    dbg(a,res);
    return res+second_case(a);
}

void solve()
{
    vector<int>a(3);
    for(int i = 0;i<3;++i)cin >> a[i];
    sort(all(a),greater<int>());
    cout << min((a[0]+a[1]+a[2])/3, a[1]+a[2]);
    
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}