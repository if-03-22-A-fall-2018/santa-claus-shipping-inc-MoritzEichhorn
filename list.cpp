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
  return (List*)malloc(sizeof(List));
}

void list_delete(List *list){

}

void list_add(List *list, void *data)
{
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = (Node*)data;

  if(list->head == 0)
  {
    list->head = newNode;
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
