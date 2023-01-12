#include<stdio.h>

void quicksort(int arr[], int first, int last){
    int i,j,pivot,temp;

    if(first<last){
        pivot = first;
        i = first;
        j = last;
        while(i<j){
            while(i<last && arr[i] <= arr[pivot])
                i++;
            while (arr[j]>arr[pivot])
                j--;
            if(i<j){
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    quicksort(arr, first, j - 1);
    quicksort(arr, j + 1, last);
            

            }        }
    }

}
int main(){
    int arr[30],n,i,;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements of array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr, 0 ,n-1);
    printf("Enter Sorted Array: \n");
    for(i=0;i<n;i++){
        printf("%d", arr[i]);
    }
    return 0;
}