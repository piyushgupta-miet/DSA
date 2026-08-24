#include <stdio.h>
#include <stdlib.h>

int main()
{
  int r1, c1;

  printf("Enter rows and columns for Matrix 1: ");
  scanf("%d %d", &r1, &c1);

  int **arr1 = (int **)malloc(r1 * sizeof(int *));
  for (int i = 0; i < r1; i++){
    arr1[i] = (int *)malloc(c1 * sizeof(int));
    for(int j = 0; j < c1; j++){
      printf("Matrix [%d][%d] : ", i, j);
      scanf("%d", &arr1[i][j]);
    }
  }

  printf("\nTranspose Matrix\n");
  for(int i = 0; i < c1; i++){
    for(int j = 0; j < r1; j++){
      printf("%d ", arr1[j][i]);
    }
    printf("\n");
  }

  for (int i = 0; i < r1; i++) free(arr1[i]);
  free(arr1);

  return 0;
}
