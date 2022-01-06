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

void solve()
{
    vector<int>values(7);
    int a=0,b=0,c=0;
    for(int i=0;i<7;++i){
        cin >> values[i];
    }
    a = values[0];
    int sum_ = values.back() - a;
    for(int i=1;i<values.size();++i){
        int remaining = sum_ - values[i];
        if (find(values.begin(),values.end(),remaining)!=values.end()){
            b=remaining;
            c=values.back()-(a+b);
            break;
        }
    }
    print(a,b,c);
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