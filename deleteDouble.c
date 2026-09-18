#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};

int size = 0;
struct Node *head = NULL;

void createList(int num){
  struct Node *temp = NULL;
  while(num != 0){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;

    if(head == NULL){
      head = newNode;
      temp = head;
      head->prev = NULL;
    }
    else{
      temp->next = newNode;
      temp->next->prev = temp;
      temp = temp->next;
    }
    num--;
    size++;
  }
}

void display(){
  struct Node *temp = head;
  while(temp->next != NULL){
    printf("%d -> ",temp->data);
    temp = temp->next;
  }
  printf("%d",temp->data);
}


void deleteAtBegin(){
  struct Node *deleteNode = NULL;
  
  if(head == NULL){
    printf("List is empty\n");
    return;
  }
  else if(head->next == NULL){
    deleteNode = head;
    head = NULL;
    free(deleteNode);
    deleteNode = NULL;
    size--;
    return;
  }

  deleteNode = head;
  head = head->next;
  head->prev = NULL;
  free(deleteNode);
  deleteNode = NULL;
  size--;
}

void deleteAtEnd(){
  struct Node *deleteNode = NULL;
  
  if(head == NULL){
    printf("List is empty\n");
    return;
  }
  else if(head->next == NULL){
    deleteNode = head;
    head = NULL;
    free(deleteNode);
    deleteNode = NULL;
    size--;
    return;
  }

  struct Node *temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  deleteNode = temp;
  temp->prev->next = NULL;
  free(deleteNode);
  deleteNode = NULL;
  size--;
}

void deleteAtPos(){
  
  int pos;
  printf("Enter a position: ");
  scanf("%d",&pos);
  
  if(pos < 1 || pos > size){
    printf("Invalid position\n");
    return;
  }
  else if(pos == 1){
    deleteAtBegin();
    return;
  }
  else if(pos == size){
    deleteAtEnd();
    return;
  }
  
  struct Node *temp = head;
  struct Node *deleteNode = NULL;
  int i = 1;
  while(i < pos){
    temp = temp->next;
    i++;
  }
  deleteNode = temp;
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  free(deleteNode);
  deleteNode = NULL;
  size--;
}
int main(){
  createList(5);
  deleteAtPos();
  display();
}