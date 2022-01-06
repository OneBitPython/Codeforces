#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

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

bool possible(int mid, vector<int>&attacks, int h){
    
    int damage = 0;
    for(int i =0;i<attacks.size()-1;++i){
        damage+=(min(attacks[i+1]-attacks[i], mid));
    }
    return (damage >=h);
}
int large = pow(100,500);
void solve()
{
    int n, h;
    vector<int> attacks;
    cin >> n >> h;
    for(int i = 0; i<n;++i){
        int q;
        cin >> q; 
        attacks.pb(q);

    }    
    attacks.push_back(large);

    int l=0, r=1e18;
    while(l+1<r){
        int mid = (l+r)/2;
        if(possible(mid, attacks, h)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r << endl;
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