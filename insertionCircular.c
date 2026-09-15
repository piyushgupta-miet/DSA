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
  while(temp->next != head){
    printf("%d -> ",temp->data);
    temp = temp->next;
  }
   printf("%d",temp->data);
}


void insertAtBegin(){
  struct Node *temp = head;
  int val;
  printf("Enter a value: ");
  scanf("%d",&val);

  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = val;
  newNode->next = NULL;

  if(head == NULL){
    head = newNode;
    head->next = head;
    size++;
    return;
  }
  while(temp->next != head){
    temp = temp->next;
  }
  newNode->next = head;
  head = newNode;
  temp->next = head;
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

  if(head == NULL){
    head = newNode;
    head->next = head;
    size++;
    return;
  }
  while(temp->next != head){
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = head;
  size++;
}

void insertAtPos(){
  struct Node *temp = head;

  int pos;
  printf("Enter a position: ");
  scanf("%d",&pos);

  if(pos < 1 || pos > size){
    printf("Invalid position\n");
    return;
  }
  else if(pos == 1){
    insertAtBegin();
    return;
  }
  else if(pos == size){
    insertAtEnd();
    return;
  }

  int val;
  printf("Enter a value: ");
  scanf("%d",&val);

  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = val;
  newNode->next = NULL;

  int i = 1;
  while(i < pos-1){
    temp = temp->next;
    i++;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  size++;
}
int main(){
  createList(5);
  insertAtPos();
  display();
}