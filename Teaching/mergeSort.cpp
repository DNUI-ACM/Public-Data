#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#define N 1005
void helpMergeSort(int * begin ,int * end, int * tbegin, int * tend){

    if(begin + 1 >= end)
        return;
    int midIndex = (end - begin) / 2;
    helpMergeSort(begin , begin + midIndex , tbegin , tbegin + midIndex);
    helpMergeSort(begin + midIndex , end , tbegin + midIndex , tend);
    int * l = begin;
    int * r = begin + midIndex;
    int cnt = 0;
    while(l < begin + midIndex || r < end){
        if(!(l < begin + midIndex)){
            *(tbegin + cnt++) = *r++;
        }else if(!(r < end)){
            *(tbegin + cnt++) = *l++;
        }else if(*l < *r){
            *(tbegin + cnt++) = *l++;
        }else{
            *(tbegin + cnt++) = *r++;
        }
    }
    memcpy(begin , tbegin , sizeof(int) * (end - begin));
}
void mergeSort(int * begin , int * end){
    int * temp = (int *)malloc(sizeof(int) * (end - begin));
    helpMergeSort(begin , end , temp , temp + (end - begin));
    free(temp);
}
int main(){
    int arr[N];
    for(int j = 0;j != N;j++)
        arr[j] = rand() % N;
    for(int j = 0;j != N;j++)
        printf("%d ",arr[j]);
    putchar('\n');
    mergeSort( arr , arr + N );
    for(int j = 0;j != N;j++)
        printf("%d ",arr[j]);
    return 0;
}