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
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int,vector<int>>same_pos;
    for(int i=0;i<n;++i){
        cin >> arr[i];
        same_pos[arr[i]].pb(i);
    }
    set<int>unique(all(arr));
    if(unique.size()==n){
        cout << -1 <<endl;return;
    }
    int best = -1;
    for(auto itr= same_pos.begin();itr!= same_pos.end();++itr){
        vector<int>pos = itr->second;
        if(pos.size()>1){
            for(int i=0;i<(int)pos.size()-1;++i){
                int x = pos[i], y = pos[i+1];
                int k,k2;
                if(y-x > 1)k= n - (y-x);
                else k = n-y;
                k2 = x+1+(n-y-1);
                // print(x,y,k);
                best = max({k,best,k2});
            }
        }
    }
    cout << best << endl;
}
// 1
// 7
// 3 1 5 2 1 3 4
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