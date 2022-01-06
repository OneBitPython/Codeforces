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
    map<int,int> freq;
    for(int i=0;i<n;++i){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int q;
    cin >> q;
    vector<int> arr2 = arr;
    vector<vector<int>> dp;
    dp.pb(arr2);
    for(int i=0;i<=n;++i){
        map<int,int>freq;
        
        for(int w = 0;w<n;++w){
            freq[arr2[w]]++;
        }
        for (int w = 0;w<n;++w){
            arr2[w] = freq[arr2[w]];
        }
        dp.pb(arr2);
    }
    
    for(int j=0;j<q;++j){
        int pos,k;
        read(pos,k);
        cout << dp[min(k,n)][pos-1] << endl;
    }

}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    read(T);
    while (T--)
    {
        solve();
    }
}