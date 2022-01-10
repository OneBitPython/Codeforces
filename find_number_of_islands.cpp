#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()
#define endl '\n'
int sum()
{
    return 0;
}
template <typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n)
{
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
        if ((n & i) != 0)
        {
            val += "1";
        }
        else
        {
            val += "0";
        }
    }
    while (val.front() == '0')
    {
        val.erase(0, 1);
    }
    return val;
}

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

template <typename T>
void output_vec(vector<T> &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
template <typename one, typename two>
void output_map(map<one, two> &mp)
{
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output_set(set<T> &s)
{
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
}
int countIslands(int M[][7], int n, int m)
{
    vector<vector<int>> grid;
    for(int i=0;i<n;++i){
        vector<int> tmp;
        for(int j=0;j<m;++j){
            tmp.pb(M[i][j]);
        }
        grid.pb(tmp);
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int,int>> q;

    int ans = 0;
    int size = 0;
    for(int x=0;x<n;++x){
        for(int y=0;y<m;++y){

            size = 0;
            q.push({x,y});
            while(!q.empty()){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                // print(a, b);
                if(!visited[i][j]){
                    if(grid[i][j]==1){
                        visited[i][j] = 1;
                        size++;
                        vector<pair<int,int>> neighbours;
                        if(i<n-1)neighbours.pb({i+1, j});
                        if(i>0)neighbours.pb({i-1,j});
                        if(j>0)neighbours.pb({i,j-1});
                        if(j<m-1)neighbours.pb({i,j+1});
                        if(i<n-1 && j<m-1)neighbours.pb({i+1,j+1});
                        if(i<n-1 && j>0)neighbours.pb({i+1,j-1});
                        if(i>0 && j<m-1)neighbours.pb({i-1, j+1});
                        if(i>0 && j>0)neighbours.pb({i-1,j-1});

                        for(auto val : neighbours){
                            if(!visited[val.first][val.second])q.push(val);
                        }
                    }
                }
            }
            if(size){
                ans++;
            }
        }
    }
    return ans;
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int M[][7] = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}};

    cout << countIslands(M, 4, 2);

}