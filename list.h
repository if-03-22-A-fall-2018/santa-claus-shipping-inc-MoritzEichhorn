#ifndef SANTACLAUS_LIST_H
#define SANTACLAUS_LIST_H

typedef struct _node Node;

typedef struct _list List;

/**
 * Used to create a list structure
 */
List* list_create();

/**
 * Used to free all memory the supplied list allocated
 * (hint: list structure, including the list itself, but not the data!)
 */
void list_delete(List *list);

/**
 * Adds a new node with the supplied data to the start of the list
 */
void list_add(List *list, void *data);

/**
 * Adds a new node with the supplied data after the supplied node
 */
void list_insert_after(Node *node, void *data);

/**
 * Return the head of the list
 */
Node* list_get_first(List *list);

/**
 * Returns the next node in the list
 * (hint: be careful if the last node in the list is supplied)
 */
Node* list_get_next(Node *node);

/**
 * Retrieves the data stored in the supplied node
 * (hint: you'll probably won't be able to use this void* without casting)
 */
void* list_get_data(Node *node);

int list_get_length(List* list);

void list_delete_data_of_node(List *list);

#endif //SANTACLAUS_LIST_H
