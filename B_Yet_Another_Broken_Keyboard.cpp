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
// #define int unsigned long long
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    unordered_map<char, bool> to_take;
    for(int i=0;i<k;++i){
        char value;

        cin >> value;
        to_take[value] = true;
    }
    vector<int> arr;
    for(auto x : s){
        if(to_take[x]){
            arr.pb(1);
        }else arr.pb(0);
    }
    // output_vec(arr);
    vector<int> dp(n);
    if(arr.front() == 1)dp[0] = 1;
    for(int i = 1;i<n;++i){
        int x = arr[i];
        if(x == 1) dp[i] = dp[i-1]+1;
        else dp[i] = 0;
    }
    int sum = 0;
    for(auto x : dp)sum+=x;
    cout  << sum << endl;
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}