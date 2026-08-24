#include<stdio.h>

int insertAtStart(int arr[],int s){
  int n;
  printf("Enter number which you want to add: ");
  scanf("%d",&n);
  for(int i = s-1;i>=0;i--){
    arr[i+1] = arr[i]; 
  }
  arr[0] = n;
  return s+1;
}


int insertAtEnd(int arr[],int s){
  int n;
  printf("Enter number which you want to add: ");
  scanf("%d",&n);
  arr[s] = n;
  return s+1;
}

int insertAtPos(int arr[],int s){
  int n,pos;
  printf("Enter which position you add a number: ");
  scanf("%d",&pos);
  if(pos < 0 || pos > s){
    printf("Invalid position\n");
    return s;
  }
  printf("Enter number which you want to add: ");
  scanf("%d",&n);


  for(int i = pos;i<s+1;i++){
    int temp = arr[i];
    arr[i] = n;
    n = temp;
  }
  return s+1;
}

int main(){
  int s;
  printf("Enter the size of array : ");
  scanf("%d",&s);
  int arr[s+1];
  printf("Enter the element in array\n");
  for(int i = 0;i<s;i++){
    printf("Enter the %d element in array : ",(i+1));
    scanf("%d",&arr[i]);
  }

  int choice;
  printf("In which place you insert a number: \n1. In starting\n2. In end\n3. At given position : ");
  scanf("%d",&choice);
  switch(choice){
    case 1: s = insertAtStart(arr,s);
    break;
    case 2: s = insertAtEnd(arr,s);
    break;
    case 3: s = insertAtPos(arr,s);
    break;
    default: break;
  }

  for(int i = 0;i<s;i++){
    printf("%d ",arr[i]);
  }

  return 0;
}