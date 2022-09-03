#include <stdio.h>

int main() {
 int n1,n2,c1,c2;

 n1=0;
 n2=0;
 c1=1;
 c2=0;

scanf("%d%d",&n1,&n2);
   if((1<n1<20)&&(n2<100000)){
     for(c1=1;c1<=n2;c1++){
c2++;
        if(c2==n1){
            printf("%d\n",c1);
            c2=0;}
          else{
     printf("%d ",c1);

      }
    }
}
    return 0;
}