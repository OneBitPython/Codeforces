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
    int N, K;
    cin >> N >> K;
    vector<int>positives={0};
    vector<int>negatives={0};
    int g;
    for(int i=0; i<N; i++){
        cin >> g;
        if (g>0){
            positives.pb(g);
        }else{
            negatives.pb(abs(g));
        }
    }
    
    sort(all(positives));
    sort(all(negatives));
    
    int ans=0;
    for (int i=positives.size()-1;i>=0;i-=K){
        ans+=positives[i];
    }
    for (int i = negatives.size() - 1; i >= 0; i -= K)
    {
        ans += negatives[i];
    }
    cout << 2*(ans)-max(negatives.back(),positives.back()) << endl;
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >>T;
    while (T--)
    {
        solve();
    }
}