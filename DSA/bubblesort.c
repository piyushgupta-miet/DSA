#include<stdio.h>
#include<stdlib.h>

int main(){
  int n;
  printf("Enter the size of an array: ");
  scanf("%d",&n);
  int *arr = (int*) malloc(n*sizeof(int));
  for(int i = 0;i<n;i++){
    printf("Enter element in array: ");
    scanf("%d",&arr[i]);
  }


  for(int i = 0;i<n-1;i++){
    for(int j = 0;j<n-1-i;j++){
      if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }


  for(int i = 0;i<n;i++){
    printf("%d ",arr[i]);
  }

  free(arr);

  return 0;
}