#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void sort(int arr[],int n,int k);

void radixSort(int arr[],int n){
  int max = arr[0];
  for(int i = 0;i<n;i++){
    if(max < arr[i]){
      max = arr[i];
    }
  }
  int k = 0;
  while(max != 0){
    sort(arr,n,k);
    max = max / 10;
    k++;
  }
}

void sort(int arr[],int n,int k){
    int *count = (int*) calloc(10,sizeof(int));

    int p = (int)(pow(10, k) + 0.5);
    for(int i = 0;i<n;i++){
      int idx = (arr[i]/p)%10;
      count[idx]++;
    }

  for(int i = 1;i<10;i++){
    count[i] = count[i]+count[i-1];
  }
  
  int *output = (int*)malloc(n*sizeof(int));
  for(int j = n-1;j>=0;j--){
    int idx = (arr[j] / p) % 10;
    output[count[idx]-1] = arr[j];
    count[idx]--;
  }

  for(int i = 0;i<n;i++){
    arr[i] = output[i];
  }
  free(count);
  free(output);
}

int main()
{
  int n;
  printf("Enter the size of an array: ");
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    printf("Enter element in array: ");
    scanf("%d", &arr[i]);
  }

  radixSort(arr,n);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  free(arr);

  return 0;
}