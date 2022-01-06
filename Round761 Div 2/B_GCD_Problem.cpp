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
    if (N%2==0){
        cout << N-3 << " " << 2 << " " <<1 << endl;
    }else{

        int pointer1 = 2, pointer2 = N-3;
        while (pointer1!=pointer2){
            if (__gcd(pointer1, pointer2)==1){
                break;
            }
            pointer1++;
            pointer2--;
        }
        cout << pointer1 << " " << pointer2 << " " << 1 << endl;
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