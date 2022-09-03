#include <stdio.h>

int main() {
 float  num,total,media;
  int cont,numt;
     numt = 0;
     total = 0;
     media = 0;
  
        for (cont = 1; cont <= 6; cont++) {
          scanf("%f", &num);
        if (num > 0) {
          numt += 1;
          total += num;
       }
      }
      media = total / numt;

     printf("%d valores positivos\n", numt);
     printf("%.1f\n",media);
    return 0;
}