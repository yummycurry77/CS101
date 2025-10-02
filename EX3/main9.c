#include <stdio.h>


int main(){
    int x=1;
    int y=2;
    int z=3;
    if(x<0){
        int sum=(x*-1)*100+y*10+z;
        printf("%d",sum*-1);
    }
    else
        printf("%d",x*100+y*10+z);
    return 0;
}
