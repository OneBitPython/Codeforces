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

/*
if it's a '>'


if(cntl('>') >= cntr('<')) you end right, find sum of first cntr("<") to the left and sum of all "<" to the right, add cost from i to n+1

if cntl ('>') < cntr('<') you end left, find sum of first cntl('>')+1 "<' to the right. and sum of all ">" to the left, add cost from i to 0


if it's a '<'
< > > > < < < 

if(cntl(">") <= cntr("<")) you end left, find sum of first cntl('>') to the right and sum of all ">" to the left, add cost from i to 0

if cntl('>') > cntr('<') you end right, find sum of first cntr('<') + 1 to the left and sum of all '<' to the right, add cost from i to n+1
*/

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "0"+s;
    vector<int>prefr(n+1),prefl(n+1);
    int curr = 1;
    for(int i = 1;i<=n;++i){
        if(s[i]=='<')prefr[curr] = prefr[curr-1] + i,curr++;
    }
    curr = 1;
    for(int i = 1;i<=n;++i){
        if(s[i]=='>')prefl[curr] = prefl[curr-1] + i,curr++;
    }
    int dl = 0, dr = 0; 
    int tr = count(all(s),'<'), tl = count(all(s),'>');

    for(int i = 1;i<=n;++i){
        if(s[i]=='<')dr++;
        int cntl = dl, cntr = tr-dr;
        if(s[i]=='>'){
            if(cntl >= cntr){
                int suml = prefl[dl] - prefl[dl-cntr];
                int sumr = prefr[tr] - prefr[dr];
                suml = (i*cntr) - suml;
                sumr -= (i*(tr-dr));
                cout << 2*(suml + sumr) + (n+1-i) << ' ';
            }else{
                int suml = prefl[dl], sumr = prefr[dr+cntl+1] - prefr[dr];
                suml = (i*dl)-suml;
                sumr-=(i*(cntl+1));
                cout << 2*(suml+sumr) + i << ' ';
            }
            dl++;
        }else{  
            if(cntl <= cntr){
                int suml = prefl[dl], sumr = prefr[dr+cntl] - prefr[dr];
                suml = (i*dl)-suml;
                sumr -= (i*cntl);
                cout << (suml+sumr)*2 + i << ' ';
            }else{
                int sumr = prefr[tr]-prefr[dr], suml = prefl[dl] - prefl[dl-(cntr+1)];
                suml = (i*(cntr+1))-suml;
                sumr-=(i*(tr-dr));
                cout << 2*(suml + sumr) + (n+1-i) << ' ';

            }
        }
    }
    cout << endl;
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