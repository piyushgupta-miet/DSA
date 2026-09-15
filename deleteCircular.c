#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

int size = 0;
struct Node *head = NULL;

void createList(int num){
  struct Node *temp = NULL;
  if(num <= 0){
    return;
  }
  while(num != 0){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;

    if(head == NULL){
      head = newNode;
      temp = head;
    }
    else{
      temp->next = newNode;
      temp = temp->next;
    }
    num--;
    size++;
  }
  temp->next = head;
}

void display(){
  struct Node *temp = head;
  if(head == NULL){
    return;
  }
  while(temp->next != head){
    printf("%d -> ",temp->data);
    temp = temp->next;
  }
   printf("%d",temp->data);
}

void deleteAtBegin(){
  
  struct Node *delNode = NULL;
  
  if(head == NULL){
    printf("List is empty");
    return;
  }
  else if(head->next == head){
    delNode = head;
    head = NULL;
    free(delNode);
    delNode = NULL;
    size--;
    return;
  }
  struct Node *temp = head;
  while(temp->next != head){
    temp = temp->next;
  }
  delNode = head;
  head = head->next;
  temp->next = head;
  free(delNode);
  delNode = NULL;
  size--;
}

void deleteAtEnd(){
  
  struct Node *delNode = NULL;
  
  if(head == NULL){
    printf("List is empty");
    return;
  }
  else if(head->next == head){
    delNode = head;
    head = NULL;
    free(delNode);
    delNode = NULL;
    size--;
    return;
  }
  struct Node *temp = head;
  while(temp->next->next != head){
    temp = temp->next;
  }
  delNode = temp->next;
  temp->next = head;
  free(delNode);
  delNode = NULL;
  size--;
}

void deleteAtPos(){

  int pos;
  printf("\nEnter a position: ");
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
  struct Node *delNode = NULL;

  int i = 1;
  while(i < pos-1){
    temp = temp->next;
    i++;
  }
  delNode = temp->next;
  temp->next = temp->next->next;
  free(delNode);
  delNode = NULL;
  size--;
}
int main(){
  createList(5);
  display();
  deleteAtPos();
  printf("\n");
  display();
}