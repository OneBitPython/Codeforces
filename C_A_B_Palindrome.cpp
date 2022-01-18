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
    int a, b;
    string s;
    cin >> a >> b >> s;
    vector<char> arr(all(s));
    int count0 = 0, count1 = 0;
    for(auto x : s){
        if(x == '0'){
            count0++;
        }else if(x=='1'){
            count1++;
        }
    }
    int n = (a+b);
    vector<pair<int,int>> idxs;
    for(int i = 0;i<(n/2);++i){
        char first = arr[i];
        char second = arr[n-i-1];
        if(first == '?' && second!='?'){
            if(second == '0'){
                count0++;
            }else if(second=='1'){
                count1++;
            }
            arr[i] = second;
        }else if(second == '?' && first!='?'){
            if(first == '0')count0++;
            else count1++;
            arr[n-i-1] = first;
        }else if(second == '?' && first == '?'){
            idxs.pb({i, n-i-1});
        }
    }
    for(auto val : idxs){
        int x = val.first, y = val.second;
        if(count0+2 <= a){
            arr[x] = '0';
            arr[y] = '0';
            count0+=2;
        }else if (count1+2 <= b){
            arr[x] = '1';
            arr[y] = '1';
            count1+=2;
        }
    }
    
    if(n%2){
        if(arr[n/2]=='?'){
            if(count0+1<=a){
                arr[n/2] = '0';
                count0++;
            }else if(count1+1 <= b){
                arr[n/2] = '1';
                count1++;
            }
        }
    }

    if(a == count0 && b == count1){
        
        vector<char> arr2 = arr;
        reverse(all(arr2));
        if(arr2 == arr){
            for(auto x : arr)cout << x;
        }else{
            cout << -1;
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }

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