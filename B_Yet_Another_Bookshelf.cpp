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
    vector<int>arr(N);
    for(int i=0; i<N;++i){
        cin >>arr[i];
    }    
    int count = 0;
    bool found= 0;
    int lb = 0;
    int rb = 0;
    for(int i=0; i<N;++i){
        if (arr[i]==1){
            lb=i;
            break;
        }
    }
    for(int i=N-1;i>=0;--i){
        if(arr[i]==1){
            rb = i;

            break;
        }
    }
    for(int i=lb;i<rb;++i){
        if(arr[i]==0){
            count++;
        }
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