#include <stdio.h>
#include <stdlib.h>


void merge(int a[], int b[], int arr[], int n, int m)
{
  int i = 0, j = 0, k = 0;
  while (i != n && j != m){
    if (a[i] >= b[j]){
      arr[k] = b[j];
      j++;
    }
    else{
      arr[k] = a[i];
      i++;
    }
    k++;
  }

  while (i < n){
    arr[k] = a[i];
    i++;
    k++;
  }

  while (j < m){
    arr[k] = b[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int n){
  if (n <= 1)return;
  int a[n / 2], b[n - n / 2];
  int idx = 0;
  for (int i = 0; i < n / 2; i++)
  {
    a[i] = arr[idx];
    idx++;
  }

  for (int i = 0; i < (n - n / 2); i++)
  {
    b[i] = arr[idx];
    idx++;
  }

  mergeSort(a, n / 2);
  mergeSort(b, n - n / 2);

  merge(a, b, arr, n / 2, n - n / 2);
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

  mergeSort(arr, n);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  free(arr);

  return 0;
}