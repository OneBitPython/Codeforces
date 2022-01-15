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
    vector<int> a(n), t(n);
    for(int i = 0;i<n;++i)cin >> a[i];
    for(int i = 0;i<n;++i)cin >> t[i];
    if(n == k){
        cout << accumulate(all(a), 0ll) << endl; return;
    }
    vector<int> p;
    p.pb((t[0] == 1? a[0]:0));
    for(int i = 1;i<n;++i){
        if(t[i] == 0)p.pb(p[i-1]);
        else p.pb(p[i-1]+a[i]);
    }
    vector<int> p2(n);
    p2[0] = a[0];
    for(int i = 1;i<n;++i) p2[i] = p2[i-1]+a[i];
    int first = p2[k-1]+(p[n-1]-p[k-1]);
    int best = first;
    for(int i = 1;i<n-k;++i){
        int add = (p2[i+k-1]-p2[i-1]);
        int rem1 = (p[i-1]);
        int rem2 = (p.back() - p[i+k-1]);
        best = max(best,add+rem1+rem2);
    }
    int last = p2[n-1]-p2[n-k-1]+(p[n-k-1]);
    best = max(last, best);
    cout << best << endl;
    
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}