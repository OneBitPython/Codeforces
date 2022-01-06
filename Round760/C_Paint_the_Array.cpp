#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
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


// Function to find gcd of array of
// numbers
int hcf(vector<int>arr, int n)
{
    int lcf = arr[0];
    for(int i=1;i<arr.size();++i){
        lcf = __gcd(lcf, arr[i]);
    }
    return lcf;
}

void solve()
{
    int N,v;
    cin >> N;
    vector<int>first;
    vector<int> second;
    for(int i = 0; i < N;++i){
        cin >> v;
        if(i%2==0){
            first.pb(v);
        }else{
            second.pb(v);
        }
    }

    int hcf1, hcf2;
    hcf1 = hcf(first,first.size());
    bool b=true;
    for(auto val:second){
        if (val%hcf1==0){
            b=false;
            break;
        }
    }
    if (b){
        cout << hcf1 << endl;
    }else{
        hcf2 = hcf(second,second.size());
        b=true;
        for(auto val:first){
            if (val%hcf2==0){
                b=false;
                break;
            }
        }
        if(b){
            cout << hcf2 << endl;
        }else{
            cout << 0 << endl;
        }
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