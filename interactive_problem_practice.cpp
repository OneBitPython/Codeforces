#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int l = 1, r = 1000000;
    while (l != r)
    {
        int mid = (l + r + 1) / 2;
        printf("%d\n", mid);
        fflush(stdout);

        char response[3];
        scanf("%s", response);
        if (response==">=")
            r = mid - 1;
        else
            l = mid;
    }

    printf("! %d\n", l);
    fflush(stdout);
}
