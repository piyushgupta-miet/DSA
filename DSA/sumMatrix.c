#include <stdio.h>
#include <stdlib.h>
int main()
{
  int rows, cols;
  printf("Enter the size of 2D array: ");
  scanf("%d %d", &rows, &cols);

  int **arr1 = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++){
    arr1[i] = (int *)malloc(cols * sizeof(int));
    for(int j = 0;j<cols;j++){
      printf("Enter the element [%d][%d] : ",i,j);
      scanf("%d",&arr1[i][j]);
    }
  }

  
  int **arr2 = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++){
    arr2[i] = (int *)malloc(cols * sizeof(int));
    for(int j = 0;j<cols;j++){
      printf("Enter the element [%d][%d] : ",i,j);
      scanf("%d",&arr2[i][j]);
    }
  }


  for(int i = 0;i<rows;i++){
    for(int j= 0;j<cols;j++){
      arr1[i][j] = arr1[i][j]+arr2[i][j];
    }
  }

  printf("Sum of two matrix\n");
  for(int i = 0;i<rows;i++){
    for(int j= 0;j<cols;j++){
      printf("%d ",arr1[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < rows; i++){
    free(arr1[i]);
  }
  free(arr1);

  
  for (int i = 0; i < rows; i++){
    free(arr1[i]);
  }
  free(arr2);

  return 0;
}
