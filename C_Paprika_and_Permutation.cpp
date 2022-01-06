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
    cin >>N;
    vector<int>arr;
    set<int> unassigned;
    for(int i = 1; i <= N;++i){
        unassigned.insert(i);
    }
    for(int i=0 ; i<N; ++i){
        int g;
        cin >> g;
        if (unassigned.find(g)!=unassigned.end()){
            unassigned.erase(g);
        }else{
            arr.pb(g);
        }
    }
    sort(all(arr),greater<int>());

    int count = 0;
    for(auto x : arr){
        auto last = (unassigned.end());
        last--;
        int value = *last;
        if (value > (x-1)/2){
            cout << -1 << endl;
            return;
        }
        count++;
        unassigned.erase(value);
    }
    cout << count << endl;
    
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