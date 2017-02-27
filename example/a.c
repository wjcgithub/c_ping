#include "stdio.h"
int main(void){
    int n=1;
    printf("%p\n",(char *)&n);
    printf("%d\n",*(char *)&n);
    printf(*(char *)&n ? "little\n" : "big\n");
    return 0;
}
