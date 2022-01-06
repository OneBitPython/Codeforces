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

template<typename T>
void output_vec(vector<T> &v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}
template<typename one,typename two>
void output_map(map<one,two> &mp){
    for(auto itr= mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output_set(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}
void solve()
{
    int N;
    cin >> N;
    vector<int>arr(N);
    for(int i=0;i<N;++i){
        cin >> arr[i];
    }
    // check if each value is divisible by atleast one value from 2 to i where i is the index of the value+1
    for(int i=0;i<arr.size();++i){
        int divisor = i+2;
        bool b =false;
        for(int j=2;j<divisor+1;++j){
            if (arr[i]%j!=0){
                b = true;
                break;
            }
        }
        if(!b){
            cout << "NO" << endl;
            return;
        }

    }
    cout << "YES" << endl;
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