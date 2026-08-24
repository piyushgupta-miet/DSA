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
    int small = i;
    for(int j = i+1;j<n;j++){
      if(arr[small] > arr[j]){
        small = j;
      }
    }
    if(small != i){
      int temp = arr[i];
      arr[i] = arr[small];
      arr[small] = temp;
    }

  }


  for(int i = 0;i<n;i++){
    printf("%d ",arr[i]);
  }

  free(arr);

  return 0;
}