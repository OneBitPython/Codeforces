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
    // for each element store the index of first greater and first lesser to the right and first greater and first lesser to the left
    vector<int>right(n+1), left(n+1,1e18);
    stack<int>st,st2;
    for(int i = n;i>=1;--i){
        // find first greater to the right
        while(!st.empty() && a[st.top()]<a[i])st.pop();
        while(!st2.empty() && a[st2.top()]>a[i])st2.pop();
        if(st.empty())right[i] = n+1;
        else right[i] = max(right[i], st.top());

        if(st2.empty())right[i] = n+1;
        else right[i] = max(right[i],st2.top());
        st.push(i);
        st2.push(i);
    }
    while(!st.empty())st.pop();
    while(!st2.empty())st2.pop();
    for(int i = 1;i<=n;++i){
        while(!st.empty() && a[st.top()]<a[i])st.pop();
        while(!st2.empty() && a[st2.top()]>a[i])st2.pop();
        if(st.empty())left[i] = -1;
        else{
            left[i] = min(left[i], st.top());
        }

        if(st2.empty())left[i] = -1;
        else left[i] = min(left[i],st2.top());
        st.push(i);
        st2.push(i);
    }
    vector<pair<int,int>>suff(n+2);
    for(int i = n;i>=1;--i){
        if(left[i]>suff[i+1].first){
            suff[i].first = left[i];
            suff[i].second = i;
        }else suff[i] = suff[i+1];
    }
    for(int i = 1;i<=n;++i){
        if(right[i]>n)continue;
        if(suff[right[i]].first>=i){
            cout << i << ' ' << suff[right[i]].second << endl;
            return;
        }
    }
    cout <<-1 << endl;
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