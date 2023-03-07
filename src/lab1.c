#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"
#include "tokenizer.h"

int main ( void ) {
  List *list = init_history();
  char str[256];
  char *e, *p=NULL;
  
  while(1) {
    printf("> ");
    fgets(str,256,stdin);
    if ( str[0] == '!' ) {
      // print_history(list);
      e = &str[1];
      p = get_history(list,atoi(e));
      if ( p != NULL ) printf(p);
      continue;
    }
  
    printf(str);
    add_history(list,str);
    //print_history(list);
    if ( str[0] == '\n' ) break;
  }
}
