#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

typedef int T;

typedef struct {
    T * base;
    int len;
    int max_size;
    bool (*cmp)(const T *,const T *);
}Heap;

void swap(T * lsh,T * rsh){
    T temp = *lsh;
    *lsh = *rsh;
    *rsh = temp;
}
inline int father(int idx){ return (idx - 1) / 2; }
inline int lson(int idx){ return idx * 2 + 1; }
inline int rson(int idx){ return idx * 2 + 2; }
void initHeap(Heap * heap,int size,bool (*cmp)(const T *,const T *)){
    heap -> max_size = size;
    heap -> base = (T*)malloc(sizeof(T) * size);
    heap -> cmp = cmp;
    heap -> len = 0;
}
void destroyHeap(Heap * heap){
    free(heap -> base);
}
void push(Heap * heap , const T * value){
    heap->base[heap->len++] = *value;
    int cur = heap -> len - 1;
    while(cur){
        if(heap->cmp(heap->base + cur,heap->base + father(cur))){
            swap( heap->base + father(cur) , heap->base + cur);
            cur = father(cur);
        }else{
            break;
        }
    }
}
void pop(Heap * heap){
    heap->base[0] = heap->base[--heap -> len];
    int cur = 0;
    while((lson(cur) < heap -> len
        && !(heap -> cmp(heap -> base + cur , heap -> base + lson(cur))))
        || (rson(cur) < heap -> len
        && !(heap -> cmp(heap -> base + cur , heap -> base + rson(cur))))){

        if(rson(cur) < heap -> len
            && heap -> cmp(heap -> base + rson(cur) , heap -> base + lson(cur))){
            swap(heap -> base + rson(cur) , heap -> base + cur),
            cur = rson(cur);
        }
        else{
            swap(heap -> base + lson(cur) , heap -> base + cur),
            cur = lson(cur);
        }
    }
}
const T * top(Heap * heap){
    return heap->base;
}
bool smaller(const int * lsh,const int * rsh){
    return *lsh < * rsh;
}
int main(){
    Heap heap;
    initHeap(&heap , 100 , smaller);
    for(int j = 0;j != 100;j++){
        int temp = rand() % 100;
        push(&heap , &temp);
    }
    while(heap.len != 0){
        printf("%d\n",*top(&heap));
        pop(&heap);
    }
    return 0;
}