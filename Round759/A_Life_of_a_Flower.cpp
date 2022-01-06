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

void solve()
{
    int N;
    cin >> N;
    vector<int> watered(N);
    for(int i = 0; i < N;++i){
        cin >> watered[i];
    }
    int length=1;
    bool b=true;
    for(int i=0;i<N;++i){
        if(watered[i]==0){
            if (i>0 && watered[i-1]==0){
                cout << -1 << endl;
                b=false;
                break;
            }
        }else{
            if (i>0 && watered[i-1]==1){
                length+=5;
            }else{
                
                length++;
            }
        }
    }
    if(b){
        cout << length << endl;
    }

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