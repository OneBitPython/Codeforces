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
    vector<string> pos = {"aa", "aca","aba","acba","abbacca","accabba","abca"};

    int N;
    cin >> N;
    string s;

    cin >> s;
    int smallest = 8;
    bool b=false;
    for(int i=2;i<=7;++i){
        if(b){
            break;
        }
        for(int j=0;j<s.size();j++){
            string comp = s.substr(j,i);
            if(find(all(pos),comp)!=pos.end()){
                smallest = i;
                b=true;
                break;
            }
        }
    } 
    cout << (smallest<=7?smallest:-1) << endl;
    
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