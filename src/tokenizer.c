#include <stdio.h>
#include <stdlib.h>
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

// Function returns a pointer to the first non_space_char or to null if none exist.
char *word_start(char *s){
  char *p = s;
  while (*p != '\0') {
    if (non_space_char(*p)){
      return p;
    }
    p++;
  }  
  return NULL;
}

// Function returns a pointer to the character after the end of a word...
char *word_terminator(char *word){
  char *p = word;
  while (*p != '\0' ) {
    if ( space_char(*p) ) {
      return p;
    }
    p++;
  }
  return p;
}

// Function counts the number of words in a string...
int count_words(char *s) {
  char *p, *w;
  int n=0;

  p = s;
  while ( w = word_start(p) ) {
    //printf("1 s: %s w: %s n: %d\n", p, w, n);
    p = word_terminator(w);
    ++n;
    //printf("2 s: %s w: %s n: %d\n", p, w, n);
  }
  return n;
}

// copies at most len characters from one string to another...
// assumes inStr is at least length len...
char *copy_str(char *inStr , short len) {
  char *p = malloc ((len+1) * sizeof(char));
  int i;
  for ( i=0; i<len; ++i) p[i] = inStr[i];
  p[len] = '\0';
  //printf("inStr: %s p: %s equal=%d\n",inStr,p,inStr==p);
  return p;

}
