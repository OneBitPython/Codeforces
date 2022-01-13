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
void output_vec(vector<T> &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
template <typename one, typename two>
void output_map(map<one, two> &mp)
{
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output_set(set<T> &s)
{
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> give(int s){
    int i = (s / 50) % 475;
    vector<int>value;
    for (int j = 0; j < 25; ++j)
    {
        i = (i * 96 + 42) % 475;
        value.pb(26+i);
    }
    return value;
}
void solve()
{
    int n, x, y;
    read(n,x,y);
    

    vector<int>possible;
    int best=0;
    
    for(int s= x;s<=22000;s+=50){
        vector<int>v = give(s);
        if(find(all(v),n)!=v.end()){
            // cout << s << endl;
            best = ((s-x)/100)+((s-x)%100==0?0:1);
            break;
        }
    }
    for(int s = x;s>=y;s-=50){
        vector<int>v = give(s);
        if(find(all(v),n)!=v.end() && s>=y){
            if(s <=x)cout << 0 << endl;return;

        }
    }

    cout << best << endl;
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}