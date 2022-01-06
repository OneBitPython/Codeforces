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
    int N;
    cin >> N;
    vector<string> bigrams(N-2);

    for(int i=0;i<N-2;++i){
        cin >> bigrams[i];
    }
    string ans=bigrams[0];
    for (int i=1;i<N-2;++i){
        if (bigrams[i][0]==bigrams[i-1][1]){
            ans+=bigrams[i][1];
        }else{
            ans += bigrams[i][0];
            ans += bigrams[i][1];
        }
    }
    if (ans.size()==N-1){
        ans+='b';
    }
    cout << ans << endl;
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