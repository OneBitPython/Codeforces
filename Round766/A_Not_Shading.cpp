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
    int n, m, r, c;
    read(n,m,r,c);
    r--;c--;
    vector<vector<int>> arr;
    bool has = false;
    for(int i = 0;i<n;++i){
        string s;
        cin >> s;
        vector<int> tmp;
        for(int j = 0;j<m;++j){
            if(s[j] == 'W')tmp.pb(0);
            else {tmp.pb(1);has=true;}
        }
        arr.pb(tmp);
    }
    if(!has){
        cout << -1 << endl;return;
    }
    if(arr[r][c]==1){
        cout << 0 << endl;return;
    }
    bool contains = false;
    for(int i = 0;i<n;++i){
        if(arr[i][c]){
            contains = true;break;
        }
    }
    if(contains){
        cout << 1 << endl;
    }else{
        for(int j = 0;j<m;++j){
            if(arr[r][j]){
                contains = true;break;
            }
        }
        if(contains){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }
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