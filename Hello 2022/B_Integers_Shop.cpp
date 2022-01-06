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
void solve()
{
    int n;
    cin >> n;
    int max_ = 0, min_ = 1e9;
    int cmax =1e9, cmin = 1e9;
    int c_of_longest_segment,length_of_longest_segment;
    vector<tuple<int,int,int>> arr;
    for(int i=0;i<n;++i){
        int l,r,c;
        cin >> l >> r >> c;

        if(i == 0){
            length_of_longest_segment = r - l;
            c_of_longest_segment = c;
            cout << c_of_longest_segment << endl;
            min_ = l;max_=r;cmin=c;cmax=0;
            continue;
        }

        if(l<min_ && r>max_){
            c_of_longest_segment = c;
            length_of_longest_segment = r-l;
            cout << c_of_longest_segment << endl;
            min_ = l;max_=r;cmin=c;cmax=0;
            continue;
        }
        if(r>max_){
            max_ = r;
            cmax = c;
        }
        if(r == max_){
            cmax= min(cmax, c);
        }
        if(l == min_){
            cmin = min(cmin, c);
        }
        if(l < min_){
            min_ = l;
            cmin =c;
        }
        if(c_of_longest_segment > max_-min_){
            cout << c_of_longest_segment << endl;
        }else if(c_of_longest_segment < max_-min_){
            cout << cmin + cmax << endl;
        }else{
            cout << min(cmin+cmax, c_of_longest_segment) << endl;
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