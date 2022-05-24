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


int len(int x){
    int l = 0;
    while(x){
        l++;
        x/=10;
    }
    return l;
}

void solve()
{
    int n,x;
    cin >> n >> x;
    int o = x;
    map<int,int>cost;
    cost[x] = 0;
    if(len(x) == n)cout << 0 << endl;
    else{
        vector<int>prev;
        map<int,vector<int>> adj;
        map<int,int>vis;
        prev.pb(o);
        int bord = pow(10,n);
        while(1){
            vector<int>add;
            for(auto x : prev){
                map<int,int>cnt;
                int w = x;
                while(w){
                    cnt[w%10]++;
                    w/=10;
                }
                for(int i =2 ;i<=9;++i){
                    if(!cnt[i])continue;
                    if(len(x*i) >= n && !vis[x*i]){adj[x].pb(x*i);vis[x*i] = 1;}

                    if(len(x*i) < n && !vis[x*i]){
                        add.pb(x*i);
                        vis[x*i] = 1;
                        adj[x].pb(x*i);
                    }
                }
            }
            if(add.empty())break;
            prev = add;
        }
        
        queue<int>q;
        q.push(o);
        map<int,int>costs;
        map<int,bool>visited;
        vector<int>pos;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(visited[u])continue;
            visited[u] = 1;
            for(int v : adj[u]){
                if(!visited[v]){
                    costs[v] = costs[u]+1;
                    if(len(v) < n)q.push(v);
                    else{
                        pos.pb(costs[v]);
                    }
                }
            }
        }
        if(pos.empty()){
            cout << -1 << endl;
            return;
        }
        cout << *min_element(all(pos)) << endl;
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
        // cout << "Case #" << i << ": ";
        solve();
    }
}