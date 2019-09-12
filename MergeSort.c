#include<stdio.h>

#define MAX_ARRAY 100

int DesideChange(int w[],int *i,int *j){
    int ret;
    if(w[*i] < w[*j]){
        ret = w[*i];
        *i += 1;
    }else{
        ret = w[*j];
        *j -= 1;
    }
    return ret;
}

void MergeSort(int array[],int Left,int Right){

    int i,j,k,center;
    int work[MAX_ARRAY];
    int (*funcp)(int*,int*,int*);

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

        funcp = DesideChange;

        i = Left;
        j = Right;

        for(k = Left;k <= Right;k++){
            array[k] = (*funcp)(work,&i,&j);
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
