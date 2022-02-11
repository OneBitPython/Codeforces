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
void solve()
{
    int n;
    cin>>n;
    string s, t;
    cin >> s >> t;
    int m = s.size(), k = t.size();
    int lcm = (k*m)/(__gcd(m,k));
    string ns, nt;
    for(int i = 0;i<lcm;++i){
        ns+=(s[i%m]);
    }
    for(int i = 0;i<lcm;++i){
        nt+=(t[i%k]);
    }
    auto give_ans = [&](int l){
        int q1 = 0, q2 = 0;
        for(int i = 0;i<l;++i){
            if(ns[i] == nt[i])continue;
            if(ns[i] == 'R' && (nt[i]=='S') || (ns[i] == 'P' && nt[i] == 'R') || (ns[i] == 'S' && nt[i] == 'P'))q1++;
            else q2++;
        }
        return pair<int,int>(q1, q2);
    };

    pair<int,int> res = give_ans(min(n, lcm));
    int c1 = res.first, c2 =res.second;
    if(n > lcm){
        int extra = (n/lcm);
        c1*=extra;c2*=extra;
        int rem = (n%lcm);
        res = give_ans(rem);
        c1+=res.first;
        c2+=res.second;
    }
    swap(c1, c2);
    print(c1, c2);
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // read(T);
    while (T--)
    {
        solve();
    }
}