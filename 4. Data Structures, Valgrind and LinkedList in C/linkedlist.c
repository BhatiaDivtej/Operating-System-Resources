
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linkedlist.h"

// Complete the function definitions here

/** Prepend an item to the front of the given list */
node_t *cons(int data, node_t *list) {
  node_t *new_node = (node_t *) malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = list;
  return new_node;
}

/** Get the first item in the list */
int first(node_t *list) {
  return list->data;
}

/** Get the rest of the list. */
node_t *rest(node_t *list) {
  return list->next;
}

/** Is the list empty? Return 0 if it is not empty, non-0 otherwise */
int is_empty(node_t *list) {
  return list == NULL;
}

/** Print the whole list, one item at a time. */
void print_list(node_t *list) {
  node_t *current = list;
  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->next;
  }
}

/** Free the memory held by the whole list. */
void free_list(node_t *list) {
  node_t *current = list;
  while (current != NULL) {
    node_t *next = current->next;
    free(current);
    current = next;
  }
}