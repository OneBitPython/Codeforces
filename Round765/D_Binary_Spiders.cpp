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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    map<int,int> power;
    vector<int>idxs;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        
    }
    for(int i=1;i<=n;++i){
        int v = arr[i-1];
        string bina = bin(v);

        int value = 0;
        for(int j = bina.size()-1;j>=0;++j){
            if()
        }
        if (value >= k && power[p] == 0)
        {
            idxs.pb(i + 1);
            power[p] += 1;
        }
    }
    output_vec(idxs);
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}