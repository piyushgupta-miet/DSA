#include <stdio.h>
#include <stdlib.h>

int partition(int arr[],int low,int high);
void swap(int arr[],int i,int j);

void quickSort(int arr[],int low,int high){
  if(low < high){
    int pos = partition(arr,low,high);
    quickSort(arr,low,pos-1);
    quickSort(arr,pos+1,high);
  }
}

int partition(int arr[],int low,int high){
  int i = low;
  int j = high;
  int pivot = arr[low];
  while(i < j){
    while(i<=high && arr[i] <= pivot)i++;
    while(j>=low && arr[j] > pivot)j--;
    if(i < j){
      swap(arr,i,j);
    }
  }
  swap(arr,low,j);
  return j;
}

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
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

  quickSort(arr,0,n-1);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  free(arr);

  return 0;
}