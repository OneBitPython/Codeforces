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

struct segtree{
    int size = 1;
    vector<int> maxes;
    void init(int n){    
        while(size < n)size*=2;
        maxes.assign(size*2, 0);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            maxes[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i, v, 2*x+1, lx, m);
        }else{
            set(i, v, 2*x+2, m, rx);
        }
        maxes[x] = max(maxes[2*x+1], maxes[2*x+2]);
    }

    void set(int i, int v){
        set(i, v,0,0,size);
    }
    int maxv(int l, int r, int x, int lx, int rx){
        if(lx >=r || rx<=l){
            return 0;
        }
        if(lx >=l && rx<=r){
            return maxes[x];
        }
    
        int m = (lx+rx)/2;
        
        int left = maxv(l, r, 2*x+1, lx, m);
        int right = maxv(l, r, 2*x+2, m, rx);
        return max(left, right);
    }
    
    int maxv(int l, int r){
        
        return maxv(l, r, 0, 0, size);
    }
};

void solve()
{
    int n;cin >> n;
    queue<int> poly;
    vector<int> mono;
    for(int i=0;i<n;++i){
        int type;
        cin >> type;
        if(type == 1){
            int cost;
            cin >> cost;
            poly.push(cost);
            mono.pb(cost);
        }else if (type == 2){
            
        }
    }
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}