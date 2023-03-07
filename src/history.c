#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

// Function to initialize a List data structure with NULL
List* init_history() {
  // Calloc creates memory and sets to NULL
  List* head = calloc( 1,  ( sizeof (List) ) );
  return head;
}

// Adds str to list 
void add_history(List *list, char *str){
  Item *temp;
  int id = 1;
  int len = len_str(str)+1;
  Item *item = calloc(1,sizeof(Item));
  char *copy = copy_str(str,(short int) len);
  
  if ( list == NULL ) return;
  
  // Empty list so first element is *str
  if ( list->root == NULL ) {
    item->id = id;
    item->str = copy;
    item->next = NULL;
    list->root = item;
    return;
  }

  // List has at least 1 item
  temp = list->root;
  id++;

  // Increment pointer and ID number till last element
  while ( temp->next != NULL ) {
    temp = temp->next;
    id++;
  }

  // Found last element 
  item->id = id;
  item->str= copy;
  item->next = NULL;
  temp->next = item;
}

// Get the contents at a specifc ID in the list
char *get_history(List *list, int id) {
  char* final;
  Item *t;

  if ( list == NULL ) return NULL;
  
  t = list->root;
  while ( id > 1 && t != NULL ){
    id--;
    t = t->next;
  }
  
  final = (t != NULL) ? t->str : NULL;
  return final;
}

// Traverse list and print until NULL is found
void print_history(List *list){
  Item *t;

  // Nothing to print
  if (list == NULL) return;

  t = list->root;
  while ( t != NULL ) {
    printf("%d: %s\n",t->id,t->str);
    t = t->next;
  }
  return;
}

void free_history(List *list){
  Item *t;
  Item *p;
  
  if (list == NULL) return;
  
  t= list->root;
  if(t == NULL ) return;

  p = t;
  while (t->next != NULL ){
    t = t->next;
    free(p->str);
    free(p);
    p = t;
  }
  free(p);
  list->root = (Item *) NULL;
  return;
}
