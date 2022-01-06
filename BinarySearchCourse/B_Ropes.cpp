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

bool possible(double x, vector<int>&arr, int K){
    int count = 0;
    for(auto y : arr){
        count+=((y/x));

    }
    return (count >= K);
}
int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int>values(N);
    for(int i=0;i<N;++i){
        cin >> values[i];
    }
    double l = 0,r = 1e8;
    for (int i=0;i<100;++i){
        double mid = (l+r)/2;
        if (possible(mid, values, K)==1){
            l = mid;
        }else{
            r = mid;
        }
    } 
    cout << setprecision(20);
    cout << l << endl;
}
