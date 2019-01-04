#include "child_data_mgmt.h"

struct _childDataMgmt{
 List* list;
};

ChildDataMgmt* cdm_create(){
  ChildDataMgmt* crnt = (ChildDataMgmt*)malloc(sizeof(ChildDataMgmt));
  crnt->list = list_create();
  return crnt;
}

void cdm_add_data(ChildDataMgmt *cdm, ChildData *data){
  Node* crnt_node = list_get_first(cdm->list);
  Node* last_node_of_city = 0;

  while(crnt_node != 0){
    if(((ChildData*)list_get_data(crnt_node))->city == data->city){
      last_node_of_city = crnt_node;
    }
    else if((list_get_next(crnt_node) == 0) && (last_node_of_city == 0)){
      last_node_of_city = crnt_node;
    }
    crnt_node = list_get_next(crnt_node);
  }

  if(last_node_of_city == 0){
    list_add(cdm->list, data);
  }
  else{
    list_insert_after(last_node_of_city, data);
  }
}

Node* cdm_get_sorted_data(ChildDataMgmt *cdm){
  return list_get_first(cdm->list);
}

void cdm_delete(ChildDataMgmt *cdm){
  free(cdm);
}
