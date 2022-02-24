#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()
#define endl '\n'
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
    int n,a,b,t;
    read(n,a,b,t);
    string s;
    cin >> s;
    int ans = 0,value=0;
    for(int i=0;i<n;++i){
        if(value >= t){
            break;
        }
        if(s[i] == 'w'){
            value+=b;
        }
        if(value >= t){
            break;
        }
        if(value +1 <=t){
            ans++;value++;
        }else{
            break;
        }
        value+=a;
    }
    int ans2=0,value2=0;
    if(s[0]=='w'){
        value2+=b;
    }
    value2++;
    if(value2<=t){
        ans2++;
    }
    value2+=a;
    for(int i=n-1;i>=1;i--){
        if(value2>=t){
            break;
        }
        if(s[i] == 'w')value2+=b;
        if(value2 >=t){
            break;
        }
        if(value2+1<=t){
            ans2++;
            value2++;
        }else{
            break;
        }
        value2+=a;
    }
    int best = max(ans,ans2);
    
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}