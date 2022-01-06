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
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<char> arr(s.begin(),s.end());

    int prev_count = 0;
    for(int i=0;i<N-2;++i){
        string s = "";
        s+=arr[i];
        s+=arr[i+1];
        s+=arr[i+2];
        if (s == "abc"){
            prev_count+=1;
        }
    }  
    for(int i = 0; i<Q;++i){
        int pos; 
        char character;
        cin >> pos >> character;
        pos--;

        bool contained = 0;
        if(arr[pos]=='a'){
            if(pos <arr.size()-2){
                if (arr[pos+1]=='b' &&arr[pos+2]=='c'){
                    contained=1;
                }
            }
        }else if (arr[pos]=='b'){
            if (pos>0 && pos<arr.size()-1){
                if (arr[pos-1] == 'a' && arr[pos+1]=='c'){
                    contained=1;
                }
            }
        }else{
            if(pos >1){
                if (arr[pos-1]=='b' && arr[pos-2]=='a'){
                    contained=1;
                }
            }
        }
        arr[pos] = character;
        int new_count = prev_count;

        if(character=='a'){
            if(pos <arr.size()-2){
                if (arr[pos+1]=='b' &&arr[pos+2]=='c'){
                    new_count++;
                }
                new_count-=contained;
            }else{
                new_count-=contained;
            }
        }else if (character=='b'){
            if (pos>0 && pos<arr.size()-1){
                if (arr[pos-1] == 'a' && arr[pos+1]=='c'){
                    new_count++;
                }

                new_count-=contained;
                
            }else{
                new_count -=contained;
            }
        }else{
            if(pos >1){
                if (arr[pos-1]=='b' && arr[pos-2]=='a'){
                    new_count++;
                }
                new_count-=contained;
                
            }else{
                new_count-=contained;
            }
        }
        cout << max((long long)0,new_count) << endl;
        prev_count = max((long long)0,new_count);
    }
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}