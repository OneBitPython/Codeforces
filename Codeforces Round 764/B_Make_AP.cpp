#include <bits/stdc++.h>
using namespace std;

#define double long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

double sum()
{
    return 0;
}
template <typename... Args>
double sum(double a, Args... args) { return a + sum(args...); }

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
    double a,b,c;
    read(a,b,c);
    double diff1 = c-b;
    double diff2 = b-a;
    double req1= b+(b-c);
    if(diff1==diff2){
        cout << "YES" << endl;
    }else{
        if(req1%a==0 && a<=req1){
            cout << "YES" << endl;
        }else{
            double n = a-b;
            double q = b-n;
            // cout << q <<endl;
            if(q%c==0 && c<=q){
                cout << "YES" << endl;
            }else{
                double v = (a+c)/2;
                // cout << v <<
                if(v%b==0 && b<=v && (a+c)%2==0){
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
            }
        }
    }
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    double T;
    read(T);
    while (T--)
    {
        solve();
    }
}