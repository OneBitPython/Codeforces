#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
// #define endl "\n"

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


void query(int a, int b, int c){
    cout << a << ' ' << b << ' ' << c << endl;
}
vector<vector<int>>taken(105,vector<int>(105));
void make(set<pair<int,int>>&st){
    while(!st.empty() && taken[st.begin()->first][st.begin()->second])st.erase(st.begin());
}
void solve()
{
    int n;
    cin >> n;
    set<pair<int,int>>one,two; // all 1's go into one and all two's go into two
    for(int i = 1;i<=n;++i){
        int start =1;
        if(i%2==0)start = 2;
        for(int j = start;j<=n;j+=2)one.insert({i,j});
        start = 2;
        if(i%2==0)start = 1;
        for(int j = start;j<=n;j+=2)two.insert({i,j});
    }
    for(int i = 0;i<n*n;++i){
        int c;
        cin >> c;
        make(one);
        make(two);
        if(c==2){
            // set 1 to any free one location
            if(one.empty()){
                query(3,two.begin()->first,two.begin()->second);
                taken[two.begin()->first][two.begin()->second] = 1;
                two.erase(two.begin());
                continue; 
            }
            query(1,one.begin()->first,one.begin()->second);
            taken[one.begin()->first][one.begin()->second] = 1;

            one.erase(one.begin());
        }else if(c==1){
            // set two to a free two location
            if(two.empty()){
                query(3,one.begin()->first,one.begin()->second);
                taken[one.begin()->first][one.begin()->second] = 1;

                one.erase(one.begin());
                continue; 
            }
            
            query(2,two.begin()->first,two.begin()->second);
            taken[two.begin()->first][two.begin()->second] = 1;
            two.erase(two.begin());
        }else{
            if(!one.empty()){
                query(1,one.begin()->first,one.begin()->second);
                taken[one.begin()->first][one.begin()->second] = 1;
                one.erase(one.begin());
            }else{
                query(2,two.begin()->first,two.begin()->second);
                taken[two.begin()->first][two.begin()->second] = 1;
                two.erase(two.begin());
            }
        }
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}