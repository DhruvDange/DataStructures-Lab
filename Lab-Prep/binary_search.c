#include <stdio.h>
#include <stdlib.h>

int binSearch(int n[], int key, int low, int high){

    if(low > high){
        return -1;
    }

    int mid = (low + high) / 2;

    if(n[mid] == key){
        return mid;
    }else if(n[mid] > key){
        return (binSearch(n, key, low, mid-1));
    }else{
        return (binSearch(n, key, mid + 1, high));
    }
}