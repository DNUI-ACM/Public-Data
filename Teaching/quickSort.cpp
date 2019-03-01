#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

void quickSort(int * begin , int * end){
    if(begin + 1 >= end)
        return;
    /*
            if(end - begin <= 4){
                insertSort(begin , end);
                return;
            }
    */

    /*
            three value select middle as key.
    */
    int key = *begin;
    int * left = begin;
    int * right = end - 1;

    while(left < right){
        while(left < right && key < *right)
            right--;
        *left = *right;
        while(left < right && !(key < *left))
            left++;
        *right = *left;
    }

    *left = key;
    quickSort(begin , left);
    quickSort(left + 1 , end);
}
#define N 100000
int main(){
    int arr[N];
    for(int j = 0;j != N;j++)
        arr[j] = rand() % N;
    quickSort(arr , arr + N);
    for(int j = 0;j != N;j++)
        printf("%d ",arr[j]);
    return 0;
}