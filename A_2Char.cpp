#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

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
template<typename one,typename two>
void output_map(map<one,two> &mp){
    for(auto itr= mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output_set(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> arr;
    map<string,int>ccount;
    for(int i=0;i<n;++i){
        string s;
        cin >> s;
        arr.pb(s);
    }
    int best = 0;
    for(int i=97;i<97+26;++i){
        char val1 = i;
        
        for(int j=i;j<123;++j){
            char val2 = j;
            int count = 0;
            for(auto val : arr){
                set<char>sr(all(val));
                
                if(sr.size()==1){
                    if(*sr.begin()==val1 || *sr.begin()==val2){
                        count+=val.size();
                    }
                }else if(sr.size()==2){
                    if((*sr.begin()==val1 && *sr.rbegin()==val2) || (*sr.begin()==val2 && *sr.rbegin()==val1)){
                        count+=val.size();
                    }
                }
            }
            best = max(best,count);
        }
    }
    cout << best << endl;
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}