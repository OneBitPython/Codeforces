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
    bool b = false;
    for(int i=0;i<N;++i){
        cin >> arr[i];
        if(i>0 && arr[i] !=arr[i-1]){
            b=true;
        }
    }
    if (b){
        cout << "YES" << endl;
        int count=0;
        vector<int>remaining;
        for(int i=1;i<N;++i){
            if(arr[i]==arr[0]){
                remaining.pb(i+1);
            }else{
                cout << 1 << " " << i+1 << endl;
            }
        }
        if (!remaining.empty()){
            int value = 0;
            for(int i=0;i<N;++i){
                if(arr[i]!=arr[0]){
                    value = i+1;
                    break;
                }
            }
            for(auto x : remaining){
                cout << value << " " << x << endl;
            }
        }
    }else{
        cout << "NO" << endl;
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