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
        if(val.size()==1)break;
        val.erase(0,1);
    }
    return val;
}



string invert(string s)
{
    string res;
    for(int i = 0;i<s.size();++i){
        if(s[i] == '0')res+='1';
        else res+='0';
    }
    while(res.front()=='0'){
        if(res.size()==1)break;
        res.erase(0,1);
    }
    return res;
}
void solve()
{
    string s,t;
    cin >> s >> t;
    if(s == t){
        cout << 0 << endl;
        return;
    }
    map<string,vector<string>> adj;
    vector<string>add = {s};
    map<string,bool>taken;
    taken[s] = 1;

    int tot = s.size()+t.size();
    while(1){
        vector<string>new_add;
        for(auto x : add){
            string first = invert(x);
            string second = "x";
            if(x!="0")second=x+'0';
            if(!taken[first] && first.size()<=tot){
                taken[first] = 1;
                adj[x].pb(first);
                new_add.pb(first);
            }
            if(second=="x")continue;
            if(!taken[second]&&second.size()<=tot){
                taken[second]  =1;
                adj[x].pb(second);
                new_add.pb(second);
            }
        }
        if(new_add.size()==0)break;
        add = new_add;
    }
    queue<string>q;
    q.push(s);
    map<string,bool>visited;
    map<string,int>sz;
    sz[s] = 0;
    while(!q.empty()){
        string s = q.front();
        q.pop();
        if(visited[s])continue;
        visited[s] = 1;
        for(string v : adj[s]){
            if(!visited[v]){
                sz[v] = sz[s]+1;
                q.push(v);
            }
        }
    }
    if(sz[t] == 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << sz[t] << endl;
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
        cout << "Case #" << i << ": ";
        solve();
    }
}