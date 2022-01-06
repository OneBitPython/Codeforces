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
vector<int> arr;
bool possible(int mid,int K,int reduce,int min_){
    reduce-=(min_ - mid);
    for(int i=0;i<arr.size();++i){
        if(reduce<=0){
            return true;
        }
        reduce -= abs(arr[i]-mid);
    }
    return false;
}

void solve()
{
    int N,K;
    read(N,K);
    arr.resize(N);
    for(int i = 0; i <N;++i)
        cin >> arr[i];
    if(N==1){
        if(arr[0] > K){
            cout << arr[0]-K << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
        int sum = accumulate(all(arr),0LL);
        if (sum<=K){
            cout << 0 << endl;
        }else{
            sort(all(arr),greater<int>());

            int min_ = arr.back();
            int ans = 0,reduce = sum-K;
            int l = -min_-1e2, r = (long long)min_+1;
            int best = 1e18;
            while (l+1<r){
                int mid = (l+r)/2;
                int reduce2 = reduce;
                if(possible(mid,K,reduce2,min_)){
                    l=mid;
                    int count=(min_-mid);
                    int reduce2 = reduce-count;
                    for(auto value : arr){
                        if(reduce2<=0){
                            best = min(count,best);
                            break;
                        }
                        reduce2-=(value-mid);
                        count++;
                    }
                    
                }else{
                    r = mid;
                }
            }
            
            cout << best << endl;

        }
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