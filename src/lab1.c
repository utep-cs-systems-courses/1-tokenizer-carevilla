#include <stdio.h>
#include <string.h>

int main ( void ) {
  char str[256];
  while(1) {
    printf("> ");
    fgets(str,256,stdin);
    printf(str);
    if ( str[0] == '\n' ) break;
  }
}
