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
void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    for(int i =1;i<m;++i){
        
    }
    // int dir = 1;
    // vector<int> idxs;
    // for(int i = 0;i<n;++i){
    //     if (s[i] == t[0]){
    //         idxs.pb(i);
    //     }
    // }
    // for(auto val : idxs){
    //     int size = 0;
    //     dir = 1;
    //     for(int i = 1;i<m;++i){
    //         if(val + 1 >= n){
    //             dir = -1;
    //         }
    //         if(dir == 1){
    //             if(s[val+dir] == t[i]){
    //                 val+=dir;
    //                 size++;
    //             }else{
    //                 dir = -1;
    //                 if(val!=0){
    //                     if(s[val+dir]==t[i]){
    //                         val+=dir;
    //                         size++;
    //                     }
    //                 }
    //             }
    //         }else{
    //             if(val!=0){
    //                 if(s[val+dir] == t[i]){
    //                     val+=dir;
    //                     size++;
    //                 }else{
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     if(size+1 == m){
    //         cout << "YES" << endl;return;
    //     }
    // }
    // cout << "NO" << endl;
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