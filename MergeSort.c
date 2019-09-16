#include<stdio.h>

#define MAX_ARRAY 100

void MergeSort(int array[],int Left,int Right){

    int i,j,k,center;
    int work[MAX_ARRAY];

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
            if(work[i] < work[j]){
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

    scanf("%d",&N);
    for(i = 0;i < N;i++){
        scanf("%d",&array[i]);
    }

    MergeSort(array,0,N-1);

    printf("ソート結果：");
    for(i = 0;i < N;i++){
        printf("%d ",array[i]);
    }

    printf("\n");

    return 0;
}
