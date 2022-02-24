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
    int h, m;
    cin >> h >> m;
    
    string s;
    cin >> s;
    int ch = ((s[0]-'0')*10)+(s[1]-'0');
    int cm = ((s[3]-'0')*10)+(s[4]-'0');

    
    string chs = s.substr(0,2);
    string cms = s.substr(3,2);

    
    map<int,int>mirror = {
        {0,0},
        {1,1},
        {8,8},
        {2,5}
    };
    

    // check if there is a valid time in the curr hour
    vector<pair<int,int>> pos;
    for(int ph = 0;ph<100;++ph){
        for(int  pm = 0;pm<100;++pm){
            int fm = (pm/10)%10;
            int sm = (pm%10);
            int fh = (ph/10)%10;
            int sh = (ph%10);
            if(ph <= 9){
                fh = 0;
                sh = ph;
            }
            if(pm <= 9){
                fm = 0;
                sm = pm;
            }
            if(mirror.count(fm) == 1 && mirror.count(sm) == 1 && mirror.count(fh) == 1 && mirror.count(sh) == 1){
                int newhour = (mirror[sm]*10) + mirror[fm];
                int newminute = (mirror[sh]*10)+mirror[fh];
                if(newhour <= h && newminute <= m){
                    int dist;
                    if(newhour >= ch){
                        
                    }
                }
            }
            
            

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