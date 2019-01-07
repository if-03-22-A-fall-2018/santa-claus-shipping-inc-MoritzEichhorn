#include <stdlib.h>
#include "list.h"

struct _node{
   struct _node* next;
   void *data;
};

struct _list{
   Node* head;
};

List* list_create(){
  List* list = (List*)malloc(sizeof(List));
  list->head = 0;
  return list;
}

void list_delete(List *list){
  int length = list_get_length(list);

  for(int i = 0; i < length; i++){
    Node* head = list->head;
    list->head = head->next;
    free(head);
  }

  free(list);
}

void list_add(List *list, void *data)
{
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  if(list->head == 0)
  {
    list->head = newNode;
    list->head->next = 0;
  }
  else
  {
    newNode->next = list->head;
    list->head = newNode;
  }
}

void list_insert_after(Node *node, void *data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = node->next;
  node->next = newNode;
}

Node* list_get_first(List *list){
  return list->head;
}

Node* list_get_next(Node *node){
  return node->next;
}

void* list_get_data(Node *node){
  return node->data;
}

int list_get_length(List* list){
  int count = 0;

  Node* crnt_node = list->head;

  while(crnt_node != 0){
    count++;
    crnt_node = crnt_node->next;
  }

  return count;
}
