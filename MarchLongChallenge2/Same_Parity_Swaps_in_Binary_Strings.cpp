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

template <typename T>
void output(vector<vector<T>> &v){
    for(auto x : v){
        output(x);
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
    cin >> n;
    string s;
    cin >> s;
    int best = 0;
    
    for(int k = 0;k<1;++k){
        vector<int>odd_index_ones, odd_index_zeroes, even_index_ones, even_index_zeroes;
        for(int i = 0;i<n;i+=2){
            // even location
            if(s[i] == '0'){
                if(i+1 >= n)continue;
                if(s[i+1]!='1'){
                    // not in the correct place
                    even_index_zeroes.pb(i);
                }
            }else{
                // it's a 1
                if(i > 0){
                    if(s[i-1]!='0'){
                        even_index_ones.pb(i);
                    }
                }
            }
        }
        
        for(int i = 1;i<n;i+=2){
            if(s[i] == '0'){
                if(i+1 >= n)continue;
                if(s[i+1]!='1'){
                    odd_index_zeroes.pb(i);
                }
            }else{
                if(i > 0){
                    if(s[i-1]!='0'){
                        odd_index_ones.pb(i);
                    }
                }
            }
        }
        // sort(all(even_index_ones));
        // sort(all(even_index_zeroes));
        // sort(all(odd_index_ones));
        sort(all(odd_index_zeroes));
        if(s[0] == '1')even_index_ones.pb(0);
        if(s.back() == '0'){
            if((n-1)%2 == 0){
                even_index_zeroes.pb(n-1);
            }else odd_index_zeroes.pb(n-1);
        }
        for(int i = 0;i<n;++i){
            if(s[i] == '0'){
                if(i+1 >= n)continue;
                if(s[i+1] == '1')continue;
                if(i%2 == 0){
                    // search for a one at an odd index
                    if(!odd_index_ones.empty()){
                        swap(s[i+1], s[odd_index_ones[0]]);
                        odd_index_ones.erase(odd_index_ones.begin());
                    }
                }else{
                    // search for a one at an even index
                    if(!even_index_ones.empty()){
                        swap(s[i+1], s[even_index_ones[0]]);
                        even_index_ones.erase(even_index_ones.begin());
                    }
                }
            }else{
                if(i == 0)continue;
                if(s[i-1] == '0')continue;
                if(i%2 == 0){
                    // search for a 0 at an odd index
                    if(!odd_index_zeroes.empty()){
                        swap(s[i-1], s[odd_index_zeroes[0]]);
                        odd_index_zeroes.erase(odd_index_zeroes.begin());

                    }
                }else{
                    // search for a 0 at an even index
                    if(!even_index_zeroes.empty()){
                        swap(s[i-1], s[even_index_zeroes[0]]);
                        even_index_zeroes.erase(even_index_zeroes.begin());
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0;i<n-1;++i){
            if(s[i] == '0' && s[i+1] == '1')res++;
        }
        
        best = max(res, best);
    }
    print(s);
    cout << best << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    read(T);
    while (T--)
    {
        solve();
    }
}