#include "tokenizer.h"

// Function returns true if char is space, tab, or null
int space_char(char c){
  if (( c == ' ' || c == '\t') && c != '\0') return 1;
  return 0;
}

// Function returns true if char is not a space, tab, or null
int non_space_char(char c){
  
  if ( c == ' ' || c == '\t' || c == '\0') return 0;
  return 1;
}
