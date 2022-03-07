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
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    set<int>st;
    
    map<int,int>freq;
    for(int i = 0;i<n;++i){cin >> a[i].first;a[i].second = i+1;st.insert(a[i].first);freq[a[i].first]++;}
    
    int min_ =1e9;
    vector<pair<int,int>>v = a;
    sort(all(v));
    if(st.size() == 1){
        cout << "NO" << endl;
        return;
    }
    int first = v[0].first, second = v.back().first;
    cout << "YES" << endl;
    for(auto x : a){
        if(x.first!=first){
            cout << v[0].second << ' ' << x.second << endl;
        }
    }
    for(int i = 1;i<n;++i){
        auto x = v[i];
        if(x.first == first ){
            cout << v.back().second << ' ' << x.second << endl;
        }
    }


    
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