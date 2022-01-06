#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string keyboard, text;
        cin >> keyboard >> text;

        int sum = 0;
        int prev_value = keyboard.find(text[0])+1;
        int curr_value;
        for(int j=1;j<text.length();j++){
            curr_value = keyboard.find(text[j])+1;
            sum+= abs(curr_value-prev_value);
            prev_value = curr_value;
        }
        cout << sum << endl;
    }
}