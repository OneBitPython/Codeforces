#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz sz
#define all(c) c.begin(), c.end()



string bin(long n){
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        val+="1";
      }
      else
      {
        val+="0";
      }
    }
    while(val.front()=='0'){
        val.erase(0,1);
    }
    return val;
}

void print(){cout << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cout << one << " ";
    print(rest...);
}

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

template<typename T>
void output_vec(vector<T> &v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}


template <typename T>
void output_set(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}

map<int,int> id, sz,sum,destroyed;

int root(int u){
    while(u!=id[u]) u = id[u];
    return u;
}

int merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v)return 0;
    if(sz[u] < sz[v])swap(u, v);
    id[v] = u;
    sum[u]+=sum[v];
    sz[u]+=sz[v];
    return sum[u];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n),del(n);
    
    for(int i=0;i<n;++i) cin >> arr[i];
    for(int i = 0;i<n;++i) {cin >> del[i];del[i]--;}


    for(int i = 0;i<n;++i){
        int val = arr[i];
        id[i] = i;
        sz[i] = 1;
        sum[i] = val;
        destroyed[i] = 1;
    }
    
    
    

    vector<int> res = {0};
    reverse(all(del));
    int max_ = 0;
    for(int i = 0;i<n;++i){
        
        destroyed[del[i]] = 0;
        int val = arr[del[i]];
        if(del[i]>0){
            if(!destroyed[del[i]-1]){
                val=merge(del[i], del[i]-1);
            }
        }
        if(del[i]<n-1){
            if(!destroyed[del[i]+1]){val=merge(del[i], del[i]+1);}
        }
        max_ = max(max_, val);
        res.pb(max_);
    }
    res.pop_back();
    reverse(all(res));
    for(auto x : res)cout << x << endl;
    
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}