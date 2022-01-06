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
    vector<int> arr(N);
    for(int i=0;i<N;++i){
        cin >> arr[i];
    } 
    sort(all(arr));
    int count = 0;
    int l = 0;
    int r = N-1;
    while (l<=r){
        if (arr[l]+arr[r] <=4){
            int sum =  0;
            while (sum<=4 && l<=r){
                if (sum+arr[l]+arr[r]<=4){
                    sum+=arr[l]+arr[r];
                    l++;
                    r--;
                }else{
                    if (sum+arr[l]<=4){
                        sum+=arr[l];
                        l++;
                    }else if(sum+arr[r]<=4){
                        sum+=arr[r];
                        r--;
                    }else{
                        break;
                    }
                }
            }
            count++;
        }else{
            r--;
            count++;
        }
    }
    
    cout << count << endl;
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}