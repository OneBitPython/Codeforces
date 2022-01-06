#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

void print(){cout << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cout << one << " ";
    print(rest...);
}

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

void solve()
{

}
int n, x, y;
bool possible(int val, int start){
    if (val < min(x,y)) return false;
    val -= min(x,y);
    return ((val/x)+(val/y)+1 >= n);
}


int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> x >> y;

    int l = 0, r = 2*1e9;
    while (l+1 < r){
        int mid = (l+r)/2;
        if (possible(mid, n)){
            r = mid;
        }else{
            l =mid;
        }
    }
    cout << r << endl;
}
