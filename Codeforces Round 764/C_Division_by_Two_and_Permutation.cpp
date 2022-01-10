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
    vector<int> arr;
    set<int>wanted;
    for(int i=1;i<=n;++i){
        wanted.insert(i);
    }
    // output_vec(wanted);T
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        if(x>n){
            arr.pb(x); 
        }else{
            if(wanted.count(x)==0 && x==n){
                arr.pb(x);
            }else wanted.erase(x);
        }

    }
    if(wanted.empty()){
        cout << "YES" << endl;
    }else{
        sort(all(arr));

        vector<vector<int>>all_pos;
        for(auto x :arr){
            vector<int>tmp;
            while(x!=0){
                x/=2;
                if(x<=n && x!=0){
                    tmp.pb(x);
                }
            }
            if(!tmp.empty()){
                all_pos.pb(tmp);
            }
        }
        
        sort(all(all_pos),[](auto one, auto two){
            if(one.size()==two.size()){
                for(int i=0;i<one.size();++i){
                    if(one[i]>two[i]){
                        return true;
                    }
                }
            }
            return one.size() > two.size();
        });


        for(auto x : all_pos){
            for(int i=0;i<x.size();++i){
                if(wanted.count(x[i])==1){
                    wanted.erase(x[i]);
                    break;
                }
            }
        }
        cout << (wanted.empty() ? "YES" : "NO") << endl;

       

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