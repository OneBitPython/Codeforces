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
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    /*
    first player can only win if it is 2<=x<n
    let's say first player can move left towards l and right towards r from some position x
    then we are free to place y between [1,l) and (r,n] check if max of movement of y in either position is better than x's movement to the left or right

    now the case is when l <= y <= r
    if abs(x-y) is even then x will move towards y and win regardless
    if abs(x-y) is odd then x will move in the opposite direction and you have to make sure that it can move more than y

    so we have to calculate for each position the max that 
    1. y can move right
    2. y can move left
    3. x can move right
    4. x can move left
    */
    vector<int>yleft(n+1),yright(n+1),xleft(n+1),xright(n+1);
    // calculate the max that y can move right from every position ie a[y]<a[y+1]<a[y+2]..
    for(int i = 1;i<n;){
        int j = i;
        for(int k = j;k<n;++k){
            if(a[k] < a[k+1])j++;
            else break;
        }
        for(int k = i;k<=j;++k){
            if(a[k]<a[k+1])yright[k] = j-k; 
            else break;
        }
        i = j+1;
    }
    // calculate the max that x can move right from every posotion ie a[x] > a[x+1] > a[x+2]..
    for(int i = 1;i<n;){
        int j = i;
        for(int k = j;k<n;++k){
            if(a[k] > a[k+1])j++;
            else break;
        }
        for(int k = i;k<=j;++k){
            if(a[k]>a[k+1])xright[k] = j-k; 
            else break;
        }
        i = j+1;
    }
    // calc the max that y can move left from every positoin ie a[y]<a[y-1]<a[y-2]..
    for(int i = n;i>=2;){
        int j = i;
        for(int k = i;k>=2;--k){
            if(a[k] < a[k-1])j--;
            else break;
        }
        for(int k = i;k>=j;--k){
            if(a[k] < a[k-1])yleft[k] = k-j;
            else break;
        }
        i = j-1;
    }
    // calc the max that x can move left from every pos ie a[x] > a[x-1] > a[x-2]..
    for(int i = n;i>=2;){
        int j = i;
        for(int k = i;k>=2;--k){
            if(a[k] > a[k-1])j--;
            else break;
        }
        for(int k = i;k>=j;--k){
            if(a[k] > a[k-1])xleft[k] = k-j;
            else break;
        }
        i = j-1;
    }
    vector<int>prefmx(n+1),suffmx(n+2);
    for(int i = 1;i<=n;++i)prefmx[i] = max({prefmx[i-1],yright[i],yleft[i]});
    for(int i = n;i>=1;--i)suffmx[i] = max({suffmx[i+1],yright[i],yleft[i]});
    int res = 0;
    for(int i = 2;i<n;++i){
        int l = i-xleft[i], r = i+xright[i];
        int go = max(xleft[i],xright[i]), mx = 0;
        if(l > 1)mx = max(mx, prefmx[l-1]);
        if(r < n)mx = max(mx, suffmx[r+1]);
        mx = max(mx, yright[r]);
        mx = max(mx, yleft[l]);
        if(go <= mx)continue;
        // now is the case when y is placed to the left of x and abs(x-y) is odd
        if(xleft[i]>=1){
            int pos = l;
            if(xleft[i]%2 == 0)pos++;
            if(yright[pos]>=xright[i])continue;
        }
        if(xright[i]>=1){
            int pos = r;
            if(xright[i]%2==0)pos--;
            if(yleft[pos]>=xleft[i])continue;
        }
        res++;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}