

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
    vector<int> a, b, c, ab, bc, ac, abc;
    for (int i = 0; i < n; ++i)
    {
        int cost;
        cin >> cost;
        string s;

        cin >> s;
        sort(all(s));

        if (s == "A")
            a.pb(cost);
        if (s == "B")
            b.pb(cost);
        if (s == "C")
            c.pb(cost);
        if (s == "AB")
            ab.pb(cost);
        if (s == "BC")
            bc.pb(cost);
        if (s == "AC")
            ac.pb(cost);
        if (s == "ABC")
            abc.pb(cost);
    }
    // cout << a[0] + bc[0] << endl;

    sort(all(a));
    sort(all(b));
    sort(all(c));
    sort(all(ab));
    sort(all(bc));
    sort(all(ac));
    sort(all(abc));
    int min_ =  1e9;
    if(!a.empty() && !b.empty() && !c.empty()) min_ = min(min_, a[0]+b[0]+c[0]);
    if (!a.empty() && !bc.empty()) min_ = min(min_, a[0]+bc[0]);
    if(!b.empty() && !ac.empty()) min_ = min(min_, b[0]+ac[0]);
    if(!c.empty() && !ab.empty()) min_ = min(min_, c[0]+ab[0]);
    if(!abc.empty()) min_ = min(min_, abc[0]);
    if(!ab.empty() && !bc.empty()) min_ = min(min_, ab[0]+bc[0]);
    if(!ac.empty() && !ab.empty()) min_ = min(min_, ac[0]+ab[0]);
    if(!ac.empty() && !bc.empty()) min_ = min(min_, ac[0]+bc[0]);
    // min_ = min({a[0] + b[0] + c[0], a[0] + bc[0], b[0] + ac[0], c[0] + ab[0], abc[0], ab[0] + bc[0], ac[0] + ab[0], ac[0] + bc[0]});
    if(min_ == 1e9)min_ = -1;
    cout << min_ << endl;
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}