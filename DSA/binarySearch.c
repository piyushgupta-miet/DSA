#include<stdio.h>
#include<stdlib.h>

int binary(int arr[],int low,int high,int target){
  while(low <= high){
    int mid = low + (high-low)/2;
    if(arr[mid] == target){
      return mid;
    }
    else if(arr[mid] > target){
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }
  return -1;
}

int main(){
  int n;
  printf("Enter the size of an array: ");
  scanf("%d",&n);
  int *arr = (int*) malloc(n*sizeof(int));
  for(int i = 0;i<n;i++){
    printf("Enter element in array: ");
    scanf("%d",&arr[i]);
  }
  int target;
  printf("Enter target element: ");
  scanf("%d",&target);

  int low = 0;
  int check = binary(arr,0,n-1,target);
  if(check == -1){
    printf("Target is not present");
  }
  else{
    printf("Target is present");
  }
  free(arr);
  return 0;
}