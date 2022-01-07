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

bool won(vector<int>grid,int pos){
    grid[pos] = 1;
    vector<vector<int>>pos_wins = {
        {0,1,2},
        {1,2,3},
        {4,5,6},
        {5,6,7},
        {8,9,10},
        {9,10,11},
        {12,13,14},
        {13,14,15},
        {0,4,8},
        {4,8,12},
        {1,5,9},
        {5,9,13},
        {2,6,10},
        {6,10,14},
        {3,7,11},
        {7,11,15},
        {0,5,10},
        {5,10,15},
        {1,6,11},
        {4,9,14},
        {2,5,8},
        {3,6,9},
        {6,9,12},
        {7,10,13}
    };
    for(auto x : pos_wins){
        if(grid[x[0]] == 1 && grid[x[1]]==1&&grid[x[2]]==1)return true;
    }
    return false;
}
void solve()
{
    vector<int>grid;
    for(int i=0;i<4;++i){
        string s;
        cin >> s;
        for(char x : s){
            if(x == 'x'){
                grid.pb(1);
            }else if(x=='o'){
                grid.pb(0);
            }else grid.pb(2);
        }
    }
    for(int i=0;i<grid.size();++i){
        if(grid[i] == 2){
            if(won(grid,i)){
                cout << "YES" << endl;return;
            }
        }
    }
    cout << "NO" << endl;return;
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();
    // int T;
    // read(T);
    // while (T--)
    // {
    //     solve();
    // }
}