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



vector<int>primes;
map<int,vector<int>>adj;
int mx = 1e4;

int diff(int i, int j){
    int d = 0 ;
    while(i || j){
        d+=((i%10)!=(j%10));
        j/=10;
        i/=10;
    }

    return d;
}
void preprocess(){
    vector<bool>isprime(mx+1,1);
    isprime[0] = isprime[1] = 0;
    for(int i = 2;i*i<=mx;++i){
        if(isprime[i]){
            for(int j = i*i;j<mx;j+=i)isprime[j] = 0;
        }
    }
    for(int i = 1000;i<mx;++i){
        if(isprime[i])primes.pb(i);
    }
    int n = primes.size();
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
            if(i == j)continue;
            if(diff(primes[i], primes[j]) == 1){
                adj[primes[i]].pb(primes[j]);
            }
        }
    }
}
void solve()
{
    int a,b;
    cin >> a >> b;
    vector<int>dist(mx+1, 1e18);
    bool pos = 0;
    queue<int>q;
    q.push(a);
    map<int,bool>visited;
    dist[a] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == b){
            pos = 1;
        }
        if(visited[u])continue;
        visited[u] = 1;
        for(int v : adj[u]){
            if(!visited[v]){
                dist[v] = min(dist[v], dist[u]+1);
                q.push(v);
            }
        }
    }
    
    if(pos)cout << dist[b] << endl;
    else cout << "Impossible" << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    preprocess();
    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}