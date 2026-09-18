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


void insertAtBegin(){
  int val;
  printf("Enter a value: ");
  scanf("%d",&val);
  
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = val;
  newNode->next = NULL;
  newNode->prev = NULL;
  
  if(head == NULL){
    head = newNode;
    size++;
    return;
  }
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
  size++;
}

void insertAtEnd(){
  struct Node *temp = head;
  int val;
  printf("Enter a value: ");
  scanf("%d",&val);

  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = val;
  newNode->next = NULL;
  newNode->prev = NULL;

  if(head == NULL){
    head = newNode;
    size++;
    return;
  }
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
  size++;
}

void insertAtPos(){
  struct Node *temp = head;

  int pos;
  printf("Enter a position: ");
  scanf("%d",&pos);

  if(pos < 1 || pos > size+1){
    printf("Invalid position\n");
    return;
  }
  else if(pos == 1){
    insertAtBegin();
    return;
  }
  else if(pos == size+1){
    insertAtEnd();
    return;
  }

  int val;
  printf("Enter a value: ");
  scanf("%d",&val);

  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = val;
  newNode->next = NULL;
  newNode->prev = NULL;

  int i = 1;
  while(i < pos-1){
    temp = temp->next;
    i++;
  }
  newNode->next = temp->next;
  newNode->prev = temp;
  temp->next->prev = newNode;
  temp->next = newNode;
  size++;
}
int main(){
  createList(5);
  insertAtPos();
  display();
}