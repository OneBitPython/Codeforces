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
    vector<int> arr(N),backup;
    for(int i=0;i<N;++i){
        cin >> arr[i];
        backup.pb(arr[i]);
    }    
    if (N==1){
        cout <<  arr[0]*2 << endl;
        cout <<  "0 1" << endl;
        return;
    }
    sort(all(arr),greater<int>());
    map<int,vector<int>> distances;
    distances[arr[0]]={1};
    distances[arr[1]] = {-1};
    map<int,int> continuous;
    for(int i=2;i<N;++i){
        int prev = distances[arr[i-2]][continuous[arr[i-2]]];
        if (prev>=0){
            distances[arr[i]] = prev+1;
        }else{
            distances[arr[i]] = prev-1;
        }
        continuous[arr[i-2]]
    }
    vector<int>output;
    int cost = 0;
    for(auto val :backup){
        cost+=(val*abs(distances[val])*2);
        output.pb(distances[val]);
    }
    cout << cost << endl;
    for(auto x : output){
        cout << x << " ";
    }
    cout << endl;
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