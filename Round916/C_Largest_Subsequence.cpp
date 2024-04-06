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
    cin >> n;string s;cin >> s;
    s = "0"+s;// store suffix maximum
    vector<int>mx(n+2);
    char curr = 'a';
    for(int i = n;i>=1;--i){
        mx[i] = mx[i+1];
        if(s[i] >= curr)mx[i] = i;
        curr = max(curr, s[i]);
    }

    string kk = s;
    sort(kk.begin()+1, kk.end());
    if(kk==s){
        cout << 0 << endl;
        return;
    }

    string removed;
    int pos = mx[1];
    vector<int>gone(n+1);
    while(pos != 0){
        gone[pos] = 1;
        removed += s[pos];
        pos = mx[pos+1];
    }
    if(!removed.empty())sort(all(removed));
    
    int at = 0;
    string res;
    for(int i = 1;i<=n;++i){
        if(!gone[i])res+=s[i];
        else res+=removed[at],at++;
    }
    
    
    kk = res;
    sort(all(kk));
    if(kk==res){
        int c = 0;
        reverse(all(removed));
        for(int i = 0;i<removed.size();++i){
            if(removed[i]==removed[0])c++;
            else break;
        }
        cout << max((int)(removed.size())-c, 0ll) << endl;
        return;
    }
    cout << -1 << endl;
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