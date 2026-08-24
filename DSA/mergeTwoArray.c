#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,m;
  printf("Enter the size of two array: ");
  scanf("%d %d",&n,&m);
  int *arr1 = (int*) malloc(n*sizeof(int));
  int *arr2 = (int*) malloc(m*sizeof(int));

  for(int i = 0;i<n;i++){
    printf("Enter element in 1st array: ");
    scanf("%d",&arr1[i]);
  }

  for(int i = 0;i<m;i++){
    printf("Enter element in 2nd array: ");
    scanf("%d",&arr2[i]);
  }
  int new = n+m;
  arr1 = (int*) realloc(arr1,new*sizeof(int));

  int j = 0;
  for(int i = n;i<new;i++){
    arr1[i] = arr2[j];
    j++;
  }

  printf("Merge array is->\n");
  for(int i = 0;i<new;i++){
    printf("%d ",arr1[i]);
  }
  
  free(arr1);
  free(arr2);
  return 0;
}