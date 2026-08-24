#include <stdio.h>
#include <stdlib.h>

int main()
{
  int r1, c1, r2, c2;

  printf("Enter rows and columns for Matrix 1: ");
  scanf("%d %d", &r1, &c1);

  printf("Enter rows and columns for Matrix 2: ");
  scanf("%d %d", &r2, &c2);

  if (c1 != r2) {
    printf("Error: Matrix multiplication is impossible! Columns of Matrix 1 (%d) must equal Rows of Matrix 2 (%d).\n", c1, r2);
    return 1; 
  }

  int **arr1 = (int **)malloc(r1 * sizeof(int *));
  for (int i = 0; i < r1; i++){
    arr1[i] = (int *)malloc(c1 * sizeof(int));
    for(int j = 0; j < c1; j++){
      printf("Matrix 1 [%d][%d] : ", i, j);
      scanf("%d", &arr1[i][j]);
    }
  }

  int **arr2 = (int **)malloc(r2 * sizeof(int *));
  for (int i = 0; i < r2; i++){
    arr2[i] = (int *)malloc(c2 * sizeof(int));
    for(int j = 0; j < c2; j++){
      printf("Matrix 2 [%d][%d] : ", i, j);
      scanf("%d", &arr2[i][j]);
    }
  }

  int **arr3 = (int **)malloc(r1 * sizeof(int *));
  for (int i = 0; i < r1; i++){
    arr3[i] = (int *)malloc(c2 * sizeof(int));
    for(int j = 0; j < c2; j++){
      int mul = 0;
      for(int k = 0; k < c1; k++){ 
        mul += arr1[i][k] * arr2[k][j];
      }
      arr3[i][j] = mul;
    }
  }

  printf("\nResulting Multiplied Matrix (%d x %d):\n", r1, c2);
  for(int i = 0; i < r1; i++){
    for(int j = 0; j < c2; j++){
      printf("%d ", arr3[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < r1; i++) free(arr1[i]);
  free(arr1);

  for (int i = 0; i < r2; i++) free(arr2[i]);
  free(arr2);

  for (int i = 0; i < r1; i++) free(arr3[i]);
  free(arr3);

  return 0;
}
