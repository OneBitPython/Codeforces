#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

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

void output(map<int, pair<int,int>>&mp){
    for(auto itr=mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " - " << itr->second.first << " " << itr->second.second << endl;
    }
}

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

template<typename T>
void output(vector<T> &v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}
template<typename one,typename two>
void output(map<one,two> &mp){
    for(auto itr= mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}
template <typename T, typename W>
void output(pair<T, W>&p){
    cout << p.first << " " << p.second << endl;
}
template <typename T, typename W>
void output(vector<pair<T, W>> &arr){
    for(auto x : arr){
        cout << x.first << " " << x.second << endl;
    }
}

bool valid(vector<int> &a, int n){
    // O(n)
    vector<int>p1(n);
    p1[0] = a[0];
    for(int i = 1;i<n;++i){
        p1[i] = (p1[i-1]&a[i]);
    }
    vector<int>p2(n);
    p2[n-1] = a[n-1];
    for(int i = n-2;i>=0;--i)p2[i] = (p2[i+1]&a[i]);

    bool ok = 1;
    for(int i = 0;i<n-1;++i){
        if(p1[i]!=p2[i+1]){
            ok = 0;
            break;
        }
    }
    return ok;
}


int mod = 1e9+7;
int mxn = (2*1e5)+1;

vector<int>factorials;
void preprocess(){
    int res = 1;
    factorials.pb(res);
    for(int i = 1;i<=mxn;++i){
        res = ((res%mod)*(i%mod))%mod;
        factorials.pb(res);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    set<int>get;
    map<int,int> freq;
    map<int,vector<int>> idxs;
    for(int i = 0;i<n;++i){
        int u;
        cin >> u;
        a.pb(u);
        freq[u]++;
        idxs[u].pb(i);
        if(freq[u]>=2)get.insert(u);
    }
    int res = 0;
    for(auto x : get){
        vector<int>s = a;
        int tmp = s[0];
        s[0] = x;
        s[idxs[x][0]] = tmp;

        int tmp2 = a[n-1];
        s[n-1] = x;
        s[idxs[x][1]] = tmp2;
        // print(x);
        
        if(valid(s, n)){
            int first = factorials[n-2];
            int second = ((freq[x]%mod)*((freq[x]-1)%mod))%mod;
            res+=(((first%mod)*(second%mod))%mod);
        }else{
            // print("Not valid : ", x);
            // cout << 0 << endl;
            // return;
            break;
        }
    }
    cout << res << endl;
    


}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    preprocess();

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    read(T);
    while (T--)
    {
        solve();
    }
}