#include <stdio.h>
#include <math.h>
int main() {


    double a;
    double b;
    double c;
    double r;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    if (((b * b) - 4 * a * c) < 0 || a == 0)
    {
        printf("Impossivel calcular\n");
    } 
    else {
         r = sqrt((b * b) - 4 * a * c);
        printf("R1 = %.5lf\nR2 = %.5lf\n", ((-b + r) / (2 * a)), ((-b - r) / (2 * a)));
       
    }


    return 0;

}