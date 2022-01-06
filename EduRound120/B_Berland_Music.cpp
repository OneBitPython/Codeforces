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
    vector<int>arr(N);
    for(int i = 0; i < N;++i){
        cin >> arr[i];
    }
    string s;
    cin >> s;
    int count0=0,count1=0;
    vector<int> ones,zeros;
    for(int i=0;i<s.size();++i){
        char x = s[i];
        if(x=='1'){
            count1++;
            ones.pb(arr[i]);
        }else{
            count0++;
            zeros.pb(arr[i]);
        }
    }
    vector<int>pos0, pos1;
    for(int i=0;i<count0;++i){
        pos0.pb(i+1);
    }
    for(int i=count0+1;i<N+1;++i)
        pos1.pb(i);

    sort(all(ones));
    sort(all(zeros));
    map<int,int>best;
    for(int i=0;i<ones.size();++i){
        best[ones[i]] = pos1[i];
    }
    for(int i=0;i<zeros.size();++i){
        best[zeros[i]] = pos0[i];
    }
    for(auto val :arr){
        cout << best[val] << " ";
    }
    cout << endl;

    // int done0=1,done1=0;
    // for(char x :s){
    //     if(x=='0'){
    //         cout << done0 << " ";
    //         done0++;
    //     }else{
    //         cout << N-done1 << " ";
    //         done1++;
    //     }
    // }
    // cout << endl;
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