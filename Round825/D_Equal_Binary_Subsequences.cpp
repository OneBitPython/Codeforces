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
    string s;
    cin >> s;
    n*=2;
    int cnt1 = count(all(s),'1'), cnt0 = n-cnt1;
    if(cnt1%2==0 && cnt0%2==0){
        vector<int>change;
        for(int i = 0;i<n;++i){
            if(i%2)continue;
            if(s[i]==s[i+1])continue;
            if(change.empty())change.pb(i);
            else{
                if(s[change.back()]=='1'){
                    if(s[i]=='0')change.pb(i);
                    else change.pb(i+1);
                }else{
                    // you want a '1'
                    if(s[i]=='1')change.pb(i);
                    else change.pb(i+1);
                }
            }
        }
        bool ok = 1;
        if(change.size()==1)ok = 0;
        else{
            if(change.size()>2&& s[change[0]]==s[change.back()])ok = 0;
        }
        if(!ok){cout << -1 << endl;return;}
        cout << change.size() << endl;
        for(auto x : change)cout << x+1 << ' ';
        cout << endl;
        for(int i = 1;i<=n;i+=2)cout << i << ' ';
        cout << endl;
        return;
    }
    cout << -1 << endl;
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