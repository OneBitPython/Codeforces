#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

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

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}


int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n){
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        val+="1";
      }
      else
      {
        val+="0";
      }
    }
    while(val.front()=='0'){
        val.erase(0,1);
    }
    return val;
}




void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    vector<int>evens, odds;
    for(int i =0;i<n;++i){
        int v;
        cin >> v;
        if(v&1)odds.pb(v);
        else evens.pb(v);
    }
    int take_odds = k-p;
    // try putting p even  values
    vector<vector<int>> res(k);
    int taken_till = 0;
    for(auto x : evens){
        if(p > 0){
            p--;
            res[taken_till].pb(x);
            taken_till++;
        }
    }   
    int num_evens_taken = taken_till;
    // try putting k-p groups of odd values with odd number of odd values
    int tot = 0;
    for(auto x : odds){
        if(tot < take_odds){
            tot++;
            res[taken_till].pb(x);
            taken_till++;
        }
    }
    // check if p > 0
    if(p > 0){
        // we have to have more even groups
        if((take_odds-tot)%2 == 0 && (take_odds-tot)/2 == p){
            int val = 0;
            for(int i = tot;i<odds.size();++i){
                if()
            }
        }else{
            cout << "NO" << endl;
            return;
        }
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        solve();
    }
}