#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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
    int n, k, m;
    cin >> n >> k >> m;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    map<int,vector<int>>groups;
    for(int i = 0;i<n;++i){
        groups[a[i]%m].pb(a[i]);
    }
    for(auto x : groups){
        if(x.second.size() >= k){
            cout << "Yes" << endl;
            for(int i = 0;i<k;++i){
                cout << x.second[i] << ' ';
            }
            cout << endl;
            return;
        }
    }
    cout << "No" << endl;
    // sort(all(a));
    // map<int,int>freq;
    // for(auto x : a)freq[x]++;
    // for(int i = 0;i<n;++i){
    //     if(freq[a[i]]){
    //         vector<int>group;
    //         for(int q = 0;q<freq[a[i]];++q)group.pb(a[i]);
    //         freq[a[i]] = 0;
    //         for(auto x : freq){
    //             if((x.first  - a[i]) % m == 0){
    //                 for(int j = 0;j<x.second;++j){
    //                     group.pb(x.first);
    //                 }
    //                 freq[x.first] = 0;

    //             }
    //         }
    //         if(group.size() >= k){
    //             cout << "Yes" << endl;
    //             for(int t = 0;t<k;++t)cout << group[t] << ' ';
    //             cout << endl;
    //             return;
    //         }
    //     }
    // }
    // cout << "No" << endl;
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
        // cout << "Case #" << i << ": ";
        solve();
    }
}