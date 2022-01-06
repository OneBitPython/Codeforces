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

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> arr(N);

    for (int i = 0; i <N; ++i){
        cin >> arr[i];
    }
    sort(all(arr));
    for (int i = 0; i < K; ++i){
        int num ;
        cin >> num;
        //binary search
        string found = "NO";
        
        int l = 0, r = arr.size()-1;
        while (l!=r){
            int mid = l + (r - l) / 2;
            if (arr[mid] == num){
                found = "YES";
                break;
            }else if(arr[mid] < num){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        cout << found << endl;
    }
}