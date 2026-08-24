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
  int target,c = 0;
  printf("Enter target element: ");
  scanf("%d",&target);
  for(int i = 0;i<n;i++){
    if(target == arr[i]){
      printf("Target is found in array\n");
      c = 1;
      break;
    }
  }
  if(c==0)printf("Target is not found in array\n");
  free(arr);
  return 0;
}