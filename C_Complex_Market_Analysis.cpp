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
bool isprime(int n){
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; (long long)i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

void solve()
{
    int n,e;
    read(n,e);
    vector<int> arr(n);
    vector<int>prime_nums;
    for(int i = 0;i<n;++i){
        cin >> arr[i];
        if(isprime(arr[i])){
            prime_nums.pb(i);
        }
    }
    int pairs = 0;
    for(auto prime : prime_nums){
        int ptr = prime;
        int ptr2 = prime;
        int tot1 = 0, tot2 = 0;
        //front track
        while(ptr2<n){
            ptr2+=e;
            if(ptr2 >= n){
                break;
            }
            if(arr[ptr2] == 1){
                pairs++;
                tot1++;
            }else{
                break;
            }
        }
        // backtrack;
        while(ptr>0){
            ptr-=e;
            if(ptr<0){
                break;
            }
            if(arr[ptr] == 1){
                tot2++;
                pairs++;
            }else{
                break;
            }
        }
        if(tot2>0){
            pairs+=tot1;
        }
        // print(pairs,prime);
    }
    cout << pairs << endl;
    // vector<int> arr(n);
    // bool got_prime = false;
    // for(int i=0;i<n;++i){
    //     cin >> arr[i];
    //     if(!got_prime){
    //         if(isprime(arr[i])){
    //             got_prime = true;
    //         }
    //     }
    // }
    // if(!got_prime){
    //     cout << 0 << endl;
    //     return;
    // }
    // int pair = 0;
    // for(int i=0;i<n;++i){
    //     int max_k = (n-(i+1))/e;
    //     bool has_prime = false;
    //     if(isprime(arr[i])||arr[i]==1){
    //         int ks_done = 0;
    //         int ptr = i+e;
    //         if(isprime(arr[i])){
    //             has_prime = true;
    //         }
    //         if(has_prime || arr[i]==1){
    //             while(ks_done < max_k){
    //                 if(isprime(arr[ptr])){
    //                     if(has_prime){
    //                         break;
    //                     }else{
    //                         has_prime = true;
    //                     }
    //                 }else{
    //                     if(arr[ptr]!=1){
    //                         break;
    //                     }
    //                 }

    //                 if(has_prime){
    //                     ks_done++;
    //                 }
    //                 ptr+=e;
    //             }
    //         }
            
    //         if(has_prime){
    //             // print(i,ks_done);
    //             pair+=ks_done;
    //         }
    //     }
    // }
    
    // cout << pair << endl;
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