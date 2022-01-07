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
    int n,m;
    cin >> n >> m;
    
    set<int> rows, cols;
    map<int,bool> rows_found,cols_found;
    int total = n*n;
    for(int i=0;i<m;++i){
        int x, y;
        cin >> x >> y;

        rows.insert(x);cols.insert(y);
        int cdecr = cols.size();
        int rdecr = rows.size();
        bool b = false;
        if(cols_found[y]==0){
            total -= (n-rdecr);b=true;
        }
        if(rows_found[x]==0){
            total-=(n-cdecr);b=true;
        }
        if(!cols_found[y]&&!rows_found[x])total--;
        rows_found[x] = 1;
        cols_found[y] = 1;
        cout << total << " ";
    }
    
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}