#include <stdio.h>
 
int main() 
{
 int a; 
 int b;
 int c;
 int d;

 scanf("%d", &a);
 scanf("%d", &b);
 scanf("%d", &c);
 scanf("%d", &d);
 if((b>c && d>a) && (c+d>b+a) && (c >=0 && d >=0) && (a%2 ==0)){
    printf("Valores aceitos\n");
 }
    else{

 
    printf("Valores nao aceitos\n");
 }

    return 0;
}