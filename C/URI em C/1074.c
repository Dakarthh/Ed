#include <stdio.h>


int main()


{


    int N,X,y;


    scanf ("%d", &N);


    for(y=1;y<=N;y++)


    {


        scanf ("%d",&X);


        if(X==0)


            printf("NULL\n");


        else if(X<=0&&X%2==0)


            printf ("EVEN NEGATIVE\n");


        else if(X<=0&&X%2==-1)


            printf ("ODD NEGATIVE\n");


        else if(X>=0&&X%2==0)


            printf ("EVEN POSITIVE\n");


        else if(X>=0&&X%2==1)


            printf ("ODD POSITIVE\n");


    }


    return 0;


}