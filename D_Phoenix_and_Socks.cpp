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
    int n,l,r;
    cin >> n>> l >> r;
    vector<int>L(l), R(r);
    for(int &u : L)cin >> u;
    for(int &u : R)cin >> u;
    map<int,int>cntl, cntr;
    for(int i = 0;i<l;++i){
        cntl[L[i]]++;
    }
    for(int i = 0;i<r;++i){
        cntr[R[i]]++;
    }
    if(l == r){
        int pairs_made = 0;
        for(auto x : cntr){
            pairs_made+=(min(x.second, cntl[x.first]));
        }
        cout << (n/2 - (pairs_made)) << endl;
        return;
    }else if(r > l){
        // change some from cntr
        int change = (l+r)/2 - l;
        vector<pair<int,int>> ordering;
        for(auto x : cntr){
            ordering.pb({x.second - cntl[x.first], x.first});
        }
        sort(all(ordering));
        reverse(all(ordering));
        
        for(auto x : ordering){
            while(change>0 && cntr[x.second]-1>cntl[x.second]){
                cntl[x.second]++;
                cntr[x.second]--;
                change--;
            }
        }
        
        if(change > 0){
            // shift random values
            ordering.clear();
            for(auto x : cntr){
                ordering.pb({x.second - cntl[x.first], x.first});
            }
            sort(all(ordering));
            reverse(all(ordering));
            for(auto x : ordering){
                while(change > 0 && cntr[x.second] > cntl[x.second]){
                    cntr[x.second]--;
                    cntl[x.second]++;
                    change--;
                }
            }
        }
        
    }else{
        // l > r
        int change = (l+r)/2 - r;
        vector<pair<int,int>> ordering;
        for(auto x : cntl){
            ordering.pb({x.second - cntr[x.first], x.first});
        }
        sort(all(ordering));
        reverse(all(ordering));
        for(auto x : ordering){
            while(change>0 && cntl[x.second]-1>cntr[x.second]){
                cntr[x.second]++;
                cntl[x.second]--;
                change--;
            }
        }

        if(change > 0){
            // shift random values
            ordering.clear();
            for(auto x : cntl){
                ordering.pb({x.second - cntr[x.first], x.first});
            }
            sort(all(ordering));
            reverse(all(ordering));
            for(auto x : ordering){
                while(change > 0 && cntl[x.second] > cntr[x.second]){
                    cntl[x.second]--;
                    cntr[x.second]++;
                    change--;
                }
            }
        }
        
    }
    int pairs_made = 0;
    for(auto x : cntr){
        pairs_made+=(min(x.second, cntl[x.first]));
    }
    cout << (n/2 - (pairs_made))+(n/2-min(l,r)) << endl;
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