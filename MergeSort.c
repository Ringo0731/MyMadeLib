#include<stdio.h>
#include<stdbool.h>

#define MAX_ARRAY 100

bool Judge_Big_and_Smaii(const void* a,const void* b){
    int *A = (int*)a;
    int *B = (int*)b;
    return (*A < *B) ? true : false;
}

void MergeSort(void* array[],int Left,int Right){

    int i,j,k,center;
    void* work[MAX_ARRAY];

    if(Left<Right){
        center = (Left + Right)/2;
        MergeSort(array,Left,center);
        MergeSort(array,center+1,Right);

        for(i = center;i >= Left;i--){
            work[i] = array[i];
        }
        for(j = center + 1;j <= Right;j++){
            work[Right-(j-(center+1))] = array[j];
        }

        i = Left;
        j = Right;

        for(k = Left;k <= Right;k++){
            if(Judge_Big_and_Smaii(work[i],work[j])){
                array[k] = work[i++];
            }else{
                array[k] = work[j--];
            }
        }
    }
}

int main(void){

    int array[MAX_ARRAY];
    int N,i;
    //void (*sort)(void** ,int, int) = MergeSort;

    scanf("%d",&N);
    for(i = 0;i < N;i++){
        scanf("%d",&array[i]);
    }

    //(*sort)((void*)array,0,N-1);
    MergeSort((void*)array,0,N-1);

    printf("ソート結果：");
    for(i = 0;i < N;i++){
        printf("%d ",(int)array[i]);
    }

    printf("\n");

    return 0;
}
