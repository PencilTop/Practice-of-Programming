#include <stdio.h>
#define TRUE 1
#define FALSE 0

int leap_year(int year);




int main(int argc, char *argv[]) {
    /*
    *traverse the array
    int nelems = 10;
    int elem[10];
    for (int i = 0; i < nelems; i++) {
        elem[i] = i % 2 == 0? i*i : i*i*i;
    }
    for (int i = 0; i < nelems; i++) {
        printf("%d ", elem[i]);
    }
    printf("\n");
    */

    /*
    *is a leap year?
    int year = 2020;
    printf("%d %s a leap year.\n", year, leap_year(year) ? "is" : "is not");
    */
   /*
   *singular and plural number printing
   int n = 2;
   printf("The list has %d item%s\n", n, n==1? "" : "s");
   */
  


  
   return 0;
}
 
int leap_year(int year) {
    return ((year % 4 == 0) && (year % 100 != 0) || (year % 400) == 0);
}
