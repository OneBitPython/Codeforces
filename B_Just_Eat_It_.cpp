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

vector<int> arr;
int value(int l, int r){
    int best = 0;
    int sum = 0;
    
    for(int i=l;i<r;++i){
        sum = max(arr[i],arr[i] +sum);
        best = max(sum,best); 
    }
    return best;
}
void solve()
{
    int N;
    cin >> N;
    arr.resize(N);
    for(int i=0;i<N;++i){
        cin >> arr[i];
    }
    int yasser = accumulate(all(arr),0LL);
    int one = value(1,N),two = value(1,N-1),three=value(0,N-1);
    int final = max(one,max(two,three));
    cout << (yasser>final?"YES":"NO") << endl;
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