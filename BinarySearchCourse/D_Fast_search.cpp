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

}
int GreaterThanNum(int *arr, int n,  int num){
    int l = -1, r = n;
    while (r > l+1){
        int mid = (l+r) / 2;
        if (arr[mid] < num){
            l = mid;
        }else{
            r = mid;
        }
    }

    return r;
}

int LesserThanNum2(int *arr, int n,  int num)
{
    int l = -1, r = n;
    while (r > l+1){
        int mid = (l+r) / 2;
        if (arr[mid] <= num){
            l = mid;
        }else{
            r = mid;
        }
    }
    return l;
}
int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N;
    int arr[N];
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }
    cin >> K;
    sort(arr, arr+N);
    for(int i=0; i<K; ++i){
        int num, num2;
        cin >> num >> num2;
        // searching for l or best pos of l
        int l = GreaterThanNum(arr, N,  num);
        int r = LesserThanNum2(arr,N,  num2);
        cout << r-l+1 << " ";

    }
    cout << endl;
}
