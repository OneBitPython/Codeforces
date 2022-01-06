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

template<typename T>
void output_vec(vector<T>&arr){
    for(T x : arr){
        cout << x << " ";
    }
    cout << endl;
}

void read(){};
template <typename T, typename... Args>
void read(T &one, Args &...rest)
{
    cin >> one;
    read(rest...);
}

void solve()
{
    int N, M;
    read(N,M);
    vector<vector<int>> arr(N,vector<int>(M,0));
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j)
            cin>>arr[i][j];
    }
    vector<vector<int>> prefix_sums(N, vector<int>(M,0));
    prefix_sums[0][0] = arr[0][0];
    for(int i=1;i<M;++i){
        prefix_sums[0][i] = arr[0][i]+prefix_sums[0][i-1];
    }
    for(int i=1;i<N;++i){
        prefix_sums[i][0] = arr[i][0]+prefix_sums[i-1][0];
    }
    for(int i=1;i<N;++i){
        for(int j=1;j<M;++j){
            prefix_sums[i][j] = prefix_sums[i-1][j]+prefix_sums[i][j-1]+arr[i][j]-prefix_sums[i-1][j-1];
        }
    }
    int Q;
    cin >> Q;
    for(int i=0;i<Q;++i){
        int a,b,A,B;

        read(a,b,A,B);
        int area = (max(1ll, A+1-a)) * (max(1ll, B+1-b));
        

        a--;
        b--;
        A--;
        B--;

        if(a==0 && b==0){
            cout << (prefix_sums[A][B]==area) << endl;
        }else if(a==0){
            cout << (prefix_sums[A][B] - prefix_sums[A][b-1]==area) << endl;
        }else if(b==0){
            cout << (prefix_sums[A][B] - prefix_sums[a-1][B]==area) << endl;
        }else{
            cout << (prefix_sums[A][B] - prefix_sums[A][b - 1] - prefix_sums[a-1][B]+prefix_sums[a-1][b-1]==area) << endl;
        }
    }
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}