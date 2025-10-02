#include <stdio.h>

void is_2_power(int i){
    if(i&(i-1)){
        printf("false");
    }
    else{
        printf("true");
    }
}



int main(){
    int i=8;
    is_2_power(i);
    
    
    
    
    return 0;
}
