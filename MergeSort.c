#include<stdio.h>

#define MAX_ARRAY 100

int is_1st_small(void* a,void* b){
    int A = *(int*)a;
    int B = *(int*)b;
    return (A < B);
}

void MergeSort(void* array[],int left,int right,int (*must_swap)(void*,void*)){
    
    int i,j,k,center;
    void* work[MAX_ARRAY];

    if(left<right){
        center = (left + right)/2;
        MergeSort(array,left,center,must_swap);
        MergeSort(array,center+1,right,must_swap);

        for(i = center;i >= left;i--){
            work[i] = array[i];
        }
        for(j = center + 1;j <= right;j++){
            work[right-(j-(center+1))] = array[j];
        }

        i = left;
        j = right;

        for(k = left;k <= right;k++){
            if((*must_swap)(work[i],work[j]) > 0){
                array[k] = work[i++];
            }else{
                array[k] = work[j--];
            }
        }
    }
}

int main(void){

    int array[MAX_ARRAY];
    void* sorted_array[MAX_ARRAY];
    int N,i;
    int (*must_swap)(void*,void*) = is_1st_small;

    scanf("%d",&N);
    for(i = 0;i < N;i++){
        scanf("%d",&array[i]);
    }

    for(i = 0;i < N;i++){
        sorted_array[i] = (void*)&array[i];
    }

    MergeSort(sorted_array,0,N-1,must_swap);

    printf("ソート結果：");
    for(i = 0;i < N;i++){
        printf("%d ",*(int*)sorted_array[i]);
    }

    printf("\n");

    return 0;
}
