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

string bin(long n)
{
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
        if ((n & i) != 0)
        {
            val += "1";
        }
        else
        {
            val += "0";
        }
    }
    while (val.front() == '0')
    {
        val.erase(0, 1);
    }
    return val;
}

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

template <typename T>
void output(vector<T> &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
template <typename one, typename two>
void output(map<one, two> &mp)
{
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output(set<T> &s)
{
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
}
template <typename T, typename W>
void output(pair<T, W> &p)
{
    cout << p.first << " " << p.second << endl;
}
template <typename T, typename W>
void output(vector<pair<T, W>> &arr)
{
    for (auto x : arr)
    {
        cout << x.first << " " << x.second << endl;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr;
    map<int,int> freq;
    n+=2;
    // n+1 numbers added - one element gives n+2nd element
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        arr.pb(v);
        freq[v]++;
    }
    vector<int> p(n);
    p[0] = arr[0];
    for(int i = 1;i<n;++i){
        p[i] = arr[i]+p[i-1];
    }
    auto f2 = [&](int req, int idx, vector<int> &ans){
        for(auto itr = freq.begin(); itr!=freq.end();++itr){
            int x = itr->first, y = itr->second;
            if(x == req){
                y--;
            }
            if (x==arr[idx]){
                y--;
            }
            for(int i =0;i<y;++i) ans.pb(x);
        }
    };

    auto f = [&](int req, int idx,vector<int> &ans){
        if(freq.count(req) == 1){
            if(req == arr[idx]){
                if(freq[req]>1){
                    f2(req, idx, ans);
                    return true;
                }else{
                    return false;
                }
            }else{
                f2(req, idx, ans);
                return true;
            }
        }
        return false;
    };
    
    for(int i = 0;i<n;++i){
        int sum;
        if(i == 0){
            sum = p[n-1] - p[0];
        }else if (i == n-1){
            sum = p[n-2];
        }else{
            sum = (p[n-1]-p[i])+p[i-1];
        }
        
        int req = (sum - arr[i]);
        vector<int> ans;

        if(f(req, i, ans)){
            output(ans);
            return;
        }
    }
    cout << -1 << endl;

}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    read(T);
    while (T--)
    {
        solve();
    }
}