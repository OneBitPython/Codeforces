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
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N;++i){
        cin >> arr[i];
    }
    int first = arr.front();
    vector<int> tmp = {first};
    vector<vector<int>> ans;
    for(int i=1;i<N;++i){
        if (arr[i] < first){
            tmp.pb(arr[i]);
        }else{
            ans.pb(tmp);
            first=  arr[i];
            tmp={first};
        }
    }
    ans.pb(tmp);

    reverse(all(ans));
    for(auto x : ans){
        for(auto y : x){
            cout << y << " ";
        }
    }
    cout << endl;
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