#include<stdio.h>

#define MAX_ARRAY 100

int is1stSmall(void* a,void* b){
    int A = *(int*)a;
    int B = *(int*)b;
    return (A < B) ? 1 : -1;
}

void MergeSort(void* array[],int Left,int Right,int (*mustSwap)(void*,void*)){
    
    int i,j,k,center;
    void* work[MAX_ARRAY];

    if(Left<Right){
        center = (Left + Right)/2;
        MergeSort(array,Left,center,mustSwap);
        MergeSort(array,center+1,Right,mustSwap);

        for(i = center;i >= Left;i--){
            work[i] = array[i];
        }
        for(j = center + 1;j <= Right;j++){
            work[Right-(j-(center+1))] = array[j];
        }

        i = Left;
        j = Right;

        for(k = Left;k <= Right;k++){
            if((*mustSwap)(work[i],work[j]) > 0){
                array[k] = work[i++];
            }else{
                array[k] = work[j--];
            }
        }
    }
}

int main(void){

    int array[MAX_ARRAY];
    void* Sorted_array[MAX_ARRAY];
    int N,i;
    int (*mustSwap)(void*,void*) = is1stSmall;

    scanf("%d",&N);
    for(i = 0;i < N;i++){
        scanf("%d",&array[i]);
    }

    for(i = 0;i < N;i++){
        Sorted_array[i] = (void*)&array[i];
    }

    MergeSort(Sorted_array,0,N-1,mustSwap);

    printf("ソート結果：");
    for(i = 0;i < N;i++){
        printf("%d ",*(int*)Sorted_array[i]);
    }

    printf("\n");

    return 0;
}
