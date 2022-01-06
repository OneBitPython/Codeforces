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
    vector<int>arr(n);
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    int best = 0;
    for(int i=0;i<arr.size();++i){
        int count = 0,sum=0;
        for(int j=0;j<arr.size();++j){
            if(j!=i){
                if(arr[j]%2==0){
                    int value = arr[j];
                    while (value%2==0){
                        value/=2;
                        count++;
                    }
                    sum+=value;
                }else{  
                    sum+=arr[j];

                }
            }
        }
        int total = arr[i];
        for(int i=0;i<count;++i){
            total*=2;
        }
        sum+=total;
        best = max(sum,best);
    }
    cout << best << endl;
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