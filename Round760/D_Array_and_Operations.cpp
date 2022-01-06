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
    int N,K;
    cin >> N >> K;

    vector<int> arr(N),new_arr;
    for(int i=0; i<N;++i){
        cin >> arr[i];
    }
    sort(all(arr));
    // take the last 2k elements
    int ans=0;
    for(int i=N-(2*K);i<N-K;i++){
        ans+=(arr[i]/arr[i+K]);
    }
    for(int i=0;i<N-(2*K);++i){
        ans+=arr[i];
    }
    cout << ans << endl;
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