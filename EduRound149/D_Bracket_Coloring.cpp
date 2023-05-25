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
    cin >> n;string s;
    cin >> s;
    vector<int>a(n+1),res(n+1,-1);
    for(int i = 1;i<=n;++i)a[i] = (s[i-1]=='('?1:-1);
    set<pair<int,int>>pos,neg;// storse {sum,color}
    if(a[1]>0)pos.insert({0,1}); 
    else neg.insert({0,1});
    res[1] = 1;
    vector<int>suffp(n+2),suffn(n+2);
    for(int i = n;i>=1;--i)suffp[i] = suffp[i+1]+(a[i]==1),suffn[i] = suffn[i+1]+(a[i]==-1);
    int col = 1;
    
    for(int i = 1;i<=n;++i){
        if(a[i]==1){
            bool got = 0;
            if(!neg.empty() && (*(neg.begin())).first < 0){
                int val = (*(neg.begin())).first, color = (*(neg.begin())).second;
                neg.erase(neg.begin());
                res[i] = color;
                neg.insert({val+1, color});
                got = 1;
            }


            if(got)continue;
            if(!pos.empty()){
                int val = (*pos.begin()).first, color = (*pos.begin()).second;
                if(suffn[i+1] >= (val+1)){
                    got = 1;
                    res[i] = color;
                    pos.erase(pos.begin());
                    pos.insert({val+1,color});
                }
            }
            if(got)continue;
            if(suffn[i+1] < 1){
                cout << -1 << endl;
                return;
            }
            col++;
            res[i] = col;
            pos.insert({1,col});
        }else{
            bool got = 0;
            if(!pos.empty() && (*(--pos.end())).first > 0){
                int val = (*(--pos.end())).first, color = (*(--pos.end())).second;
                pos.erase(--pos.end());
                res[i] = color;
                pos.insert({val-1, color});
                got = 1;
            }

            if(got)continue;
            if(!neg.empty()){
                int val = (*(--neg.end())).first, color = (*(--neg.end())).second;
                if(suffp[i+1] >= abs(val-1)){
                    got = 1;
                    res[i] = color;
                    neg.erase(--neg.end());
                    neg.insert({val-1,color});
                }
            }
            if(got)continue;
            if(suffp[i+1] < 1){
                cout << -1 << endl;
                return;
            }
            col++;
            res[i] = col;
            neg.insert({-1,col});
        }
    }
    bool ok = 1;
    for(auto x : pos){
        if(x.first != 0)ok = 0;
    }
    for(auto x : neg){
        if(x.first!=0)ok = 0;
    }
    if(!ok){
        cout << -1 << endl;
        return;
    }
    cout << col << endl;
    for(int i = 1;i<=n;++i)cout << res[i] << ' ';
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