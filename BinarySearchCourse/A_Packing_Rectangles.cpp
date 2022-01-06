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
}
int w, h, n;

int possible(int x){
    return (x/w)*(x/h) >=n;
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> w >> h >> n;

    int l = 0;
    int r = 1;
    while(!possible(r))r*=2;

    while (r>l+1){
        int m = (l+r)/2;
        if (possible(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r << endl;
}