#include <stdio.h>
float fat(int x){
     int i; float p;
       p=1;
       for (i=1;i<=x;i++){
            p=p*i;
       }
       return p;
       }
       int main(void){
           int n,k;
           float c;

            printf("Forneça o valor de n: ");
            scanf("%d",&n);
            printf("\n");
            printf("Forneça o valor de k: ");
            scanf("%d",&k);
            printf("\n");

            c=fat(n)/(fat(k)*fat(n-k));

            printf("%f\n",c);
            return 0;
        }
