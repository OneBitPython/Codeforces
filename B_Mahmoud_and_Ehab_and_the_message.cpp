#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()
#define endl '\n'
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
void solve()
{
    int n,k,m;
    cin >> n >> k >> m;
    vector<string> arr;
    map<string,int> indexes;
    for(int i=0;i<n;++i){
        string s;
        cin >> s;
        indexes[s] = i;
        arr.pb(s);
    }
    vector<int> costs;
    for(int i=0;i<n;++i){
        int v;cin >>v;
        costs.pb(v);
    }
    vector<vector<string>> values;
    for(int i=0;i<k;++i){
        int x;
        cin >> x;
        vector<string> tmp;
        for(int j=0;j<x;++j){
            int g;
            cin >> g;
            g--;
            tmp.pb(arr[g]);
        }
        values.pb(tmp);
    }
    map<string,int> value_cost;
    for(auto x : values){
        int cost = 1e9;
        for(auto y : x){
            int idx = indexes[y];
            cost = min(cost, costs[idx]);
        }
        for(auto y : x){
            value_cost[y] = cost;
        }
    }
    int ans= 0;
    for(int i=0;i<m;++i){
        string val;cin >> val;
        ans+=value_cost[val];
    }
    cout << ans << endl;
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}