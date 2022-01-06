#include <iostream>
#include <math.h> 
using namespace std;

int countSC(int N)
{
    int res = (int)sqrt(N) + (int)cbrt(N) - (int)(sqrt(cbrt(N)));

    return res;
}

// Driver code
int main()
{
    long long T;
    cin >> T;
    while (T--){
        long long N;
        cin >> N;
        cout <<countSC(N) << endl;
        
    }
}
