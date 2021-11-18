#include <stdio.h>

void bSearch(int a[], int key, int low, int high){

    int mid;

    if(low > high)
        return -1;

    mid = (low + high) / 2;

    if(a[mid] == key){
        return mid;
    }else if(a[mid] > key){
        return bSearch(a, key, low, mid - 1);
    }else{
        return bSearch(a, key, mid + 1, high);
    }
}