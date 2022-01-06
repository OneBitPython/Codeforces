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
int32_t main()
{

    vector<int> arr = {0,1,0,1,1,1};
    int l = -1, r = arr.size();
    while (l+1 < r){
        int mid = (l+r)/2;
        cout << mid << endl;
        if (arr[mid] == 1){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r << endl;
}
