#include <stdio.h>
int main() {


    int x;
    float y;
    float consumo;
    scanf("%d", &x);
    scanf("%f", &y);

    consumo = x/y;

    printf("%.3lf", consumo);
    printf(" km/l\n");
    

    return 0;

}