#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

int sum()
{
    return 0;
}
template <typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n)
{
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
        if ((n & i) != 0)
        {
            val += "1";
        }
        else
        {
            val += "0";
        }
    }
    while (val.front() == '0')
    {
        val.erase(0, 1);
    }
    return val;
}

void print() { cout << endl; };
template <typename T, typename... Args>
void print(T one, Args... rest)
{
    cout << one << " ";
    print(rest...);
}

void read(){};
template <typename T, typename... Args>
void read(T &one, Args &...rest)
{
    cin >> one;
    read(rest...);
}

template <typename T>
void output_vec(vector<T> &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
template <typename one, typename two>
void output_map(map<one, two> &mp)
{
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output_set(set<T> &s)
{
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> bfs(int u, vector<vector<int>> &adj, vector<bool> &visited){
    queue<int> q;
    q.push(u);
    int size = 0;
    vector<int>values;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(!visited[x]){
            if(find(all(values), x) !=values.end()){
                break;
            }else{
                values.pb(x);
            }
            visited[x] = true;
            size++;
            for(auto v : adj[x]){
                if(!visited[v]){
                    q.push(v);
                }
            }
        }
    }
    return values;
}

bool dfs(int u, vector<vector<int>> &adj, vector<bool>visited, vector<int>&ans,int n){
    visited[u] = true;
    ans.push_back(u);
    
    
    if(ans.size()==n+1){
        return true;
    }
    for(int v : adj[u]){
        if(!visited[v]){
            if(dfs(v, adj, visited, ans, n))return true;
        }
    }
    ans.pop_back();
    return false;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0;i<n;++i) cin >>arr[i];
    
    if(arr.back()==0){
        for(int i = 1;i<=n+1;++i){
            cout << i << " ";
        }
        cout << endl;return;
    }
    if(n==1){
        if(arr.back()==1){
            cout << n+1 << " " << n << endl;return;
        }
    }
    int i = 0;
    bool got = false;

    for(int i  = 0;i<n-1;++i){
        if(arr[i]==0 && arr[i+1]==1)got=true;
    }
    bool not_got = true;
    if(got){
        int v = 0;
        while(i<n-1){
            if(arr[i]==0 && not_got){
                if(arr[i+1]==1){
                    cout << i+1 << " " << n+1 << " ";
                    v+=2;
                    not_got = false;
                }else{
                    cout << i+1 << " ";
                    v++;
                }
            }else{
                cout << i+1 << " ";
                v++;
            }
            i++;
        }
        if(v!=n+1)cout << n << " ";
    }else{
        if(arr.front()==1){
            cout << n+1 << " ";
            for(int i =1;i<=n;++i){
                cout << i << " " ;
            }
        }else{
            cout << -1;
        }
    }
    cout <<endl;
    


}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    read(T);
    while (T--)
    {
        solve();
    }
}