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
void output(vector<T> &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
template <typename one, typename two>
void output(map<one, two> &mp)
{
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output(set<T> &s)
{
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
}
template <typename T, typename W>
void output(pair<T, W> &p)
{
    cout << p.first << " " << p.second << endl;
}
template <typename T, typename W>
void output(vector<pair<T, W>> &arr)
{
    for (auto x : arr)
    {
        cout << x.first << " " << x.second << endl;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int> (m,0));
    vector<vector<int>> b(n, vector<int>(m, 0));
    for(int i=0;i<n;++i){
        for(int j = 0;j<m;++j) cin >> arr[i][j];
    }
    if(arr == b){
        cout << 0 << endl;return;
    }
    vector<pair<int,int>> instr;
    for(int i = 0;i<n-1;++i){
        for(int j = 0;j<m-1;++j){
            if(arr[i][j]==1 && arr[i][j+1]==1 && arr[i+1][j]==1 && arr[i+1][j+1]==1){
                b[i][j] =1;b[i][j+1] =1;b[i+1][j+1]=1;b[i+1][j]=1;
                instr.pb({i+1, j+1});
            }
        }
    }
    
    if(arr!=b){
        cout << -1 << endl;return;
    }
    if(instr.size()==0){
        cout << -1 << endl;return;
    }
    
    cout << instr.size() << endl;
    for(auto x : instr){
        output(x);
    }
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}