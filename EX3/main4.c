#include <stdio.h>

void odd_or_even(int n){
    if(n&1)
        printf("奇數");
    else
        printf("偶數");
}


int main(){
    int i=7;
    odd_or_even(i);
    
    
    return 0;
}
