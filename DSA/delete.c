#include<stdio.h>

int deleteAtStart(int arr[],int s){
  for(int i = 0;i<s-1;i++){
    arr[i] = arr[i+1]; 
  }
  return s-1;
}


int deleteAtEnd(int arr[],int s){
  return s-1;
}

int deleteAtPos(int arr[],int s){
  int pos;
  printf("Enter which index you delete a number: ");
  scanf("%d",&pos);
  if(pos < 0 || pos >= s){
    printf("Invalid position\n");
    return s;
  }

  for(int i = pos;i<s-1;i++){
    arr[i] = arr[i+1];
  }
  return s-1;
}

int main(){
  int s;
  printf("Enter the size of array : ");
  scanf("%d",&s);
  int arr[s];
  printf("Enter the element in array\n");
  for(int i = 0;i<s;i++){
    printf("Enter the %d element in array : ",(i+1));
    scanf("%d",&arr[i]);
  }

  int choice;
  printf("In which place you delete a number: \n1. In starting\n2. In end\n3. At given position : ");
  scanf("%d",&choice);
  switch(choice){
    case 1: s = deleteAtStart(arr,s);
    break;
    case 2: s = deleteAtEnd(arr,s);
    break;
    case 3: s = deleteAtPos(arr,s);
    break;
    default: break;
  }

  for(int i = 0;i<s;i++){
    printf("%d ",arr[i]);
  }

  return 0;
}