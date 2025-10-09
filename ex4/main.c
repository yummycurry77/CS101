#include <stdio.h>



int main(){
    FILE* fp;
    int a[]={0,1,2},a_read[3];
    char b[]="ABC",b_read[5];
    float c[]={1.1,1.2,1.3},c_read[5];
    
    fp=fopen("a.bin","wb+");
    fwrite(a,sizeof(a),1,fp);
    fwrite(b,sizeof(b),1,fp);
    fwrite(c,sizeof(c),1,fp);
    
    
    fseek(fp,0,SEEK_SET);
    fread(a_read,sizeof(a_read),1,fp);
    
    
    fseek(fp,sizeof(a),SEEK_SET);
    fread(b_read,sizeof(b_read),1,fp);
    
    
    fseek(fp,sizeof(a)+sizeof(b),SEEK_SET);
    fread(c_read,sizeof(c_read),1,fp);
    
    
    for(int i=0;i<3;i++){
        printf("%d ",a_read[i]);
    }
    printf("\n");
    for(int i=0;i<3;i++){
        printf("%c ",b_read[i]);
    }
    printf("\n");
    for(int i=0;i<3;i++){
        printf("%f ",c_read[i]);
    }
   
    fclose(fp);
  
    
    return 0;
}
