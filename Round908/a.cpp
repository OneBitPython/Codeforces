#include <stdio.h>
//int x=5;
int *p;

int sum(int &a){
     p=&a;
    *p=a+5;
    return(a+10);
    
}
int main(){
int x=5;
int *q;
q=&x;
    // int size1,size2;
   // size1=sizeof(test2.niga);
    // size2=sizeof(test2.nig);
    //printf("%d %d",size1,size2);
    //x=x+3;
    sum(x);
    printf("%d\n",*p);
    printf("%d\n",x);
    printf("%d",sum(x));
    printf("\n%d",*p);
}