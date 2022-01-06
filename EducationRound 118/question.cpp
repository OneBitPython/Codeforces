#include <bits/stdc++.h>
using namespace std;

void print() { cout << endl; };
template <typename T, typename... args>
void print(T one, args... rest)
{
    cout << one << " ";
    print(rest...);
}

void solve(){
    int N;
    cin >> N;
    vector<int>input;
    map<int,int>freq;
    int G;
    for (int i=0;i<N;++i){
        cin >> G;
        input.push_back(G);
        freq[G]++;
    }

    int pairs=0;
    for (int i=0;i<N;++i){

        for (int j=i+1;j<N;++j){
            int x = input[i];
            int y = input[j];

            if (x!=y){
                if (freq[x%y] == 0)
                {
                    cout << x << " " << y << endl;
                    pairs+=1;
                }
                if (pairs>=N/2){
                    break;
                }
                if (freq[y%x]==0){
                    cout << y << " " << x << endl;
                    pairs += 1;
                }
            }
        }
    }

}

int main(){
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}