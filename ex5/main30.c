#include <stdio.h>

int recursion(int n){
    if(n==0)return 0;
    //Do before
    printf("%d\n",n);
    recursion(n-1);
    //Do after
    /*
    recursion(n-1);
    printf("%d\n",n);
    */
}

int main(){
    recursion(5);

    return 0;
}
