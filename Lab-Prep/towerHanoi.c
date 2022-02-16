#include <stdio.h>
#include <stdlib.h>

void toh(int n, char from, char aux, char to)
{
    if(n==1){
        printf("Move ring %d from %d to %d", n, from, to);
        return;
    }
    toh(n-1, from, to, aux);
    printf("Move ring %d from %d to %d", n, from, to);
    toh(n-1, aux, from, to);
}

void main(){
    toh(3, 'A', 'B', 'C');
}