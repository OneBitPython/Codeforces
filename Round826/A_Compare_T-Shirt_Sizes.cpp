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
    string a,b;
    cin >>a >> b;
    int cnt1 = 0, cnt2 = 0;
    char s,t;
    if(a==b){
        cout<< "=" << endl;
        return;
    }
    for(int i = 0;i<(int)(a.size());++i){
        if(a[i]=='X')cnt1++;
        else {
            s=a[i];
            break;
        }
    }
    for(int i = 0;i<(int)(b.size());++i){
        if(b[i]=='X')cnt2++;
        else{
            t=b[i];
            break;
        }
    }
    char res;
    if(s==t){
        if(s=='S'){
            if(cnt1 > cnt2)res = '<';
            else res = '>';
        }else{
            if(cnt1 > cnt2)res = '>';
            else res = '<';
        }
    }else{
        if(s=='S')res = '<';
        if(t=='S')res = '>';
        if(s=='L')res = '>';
        if(t=='L')res = '<';
    }
    cout << res << endl;
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