#include <stdio.h>
int main () {
 int i, j;

 for (j=1;j<=5;j++) {
 i = 0;
do {
 i++;
printf ("%d",i);
}
 while (i<j);

 printf("\n");
 }
 getchar();
 return (0);
}
