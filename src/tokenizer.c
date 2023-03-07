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
    p = word_terminator(w);
    ++n;
  }
  return n;
}

// copies at most len characters from one string to another...
// assumes inStr is at least length len...
char *copy_str(char *inStr , short len) {
  // allocates memory for the string
  char *p = malloc ((len+1) * sizeof(char));
  int i;
  for ( i=0; i<len; ++i) p[i] = inStr[i];
  p[len] = '\0';  
  return p;

}

/* helper function to determine the length of a string */
int len_str(char *s) {
  int n=1;
  char *p =  s;
  
  if ( s == (char *) NULL ) return n;
  while (*p != '\0') {
    ++n;
    ++p;
  }
  return n;
}

char **tokenize(char *s){
  int i, n;
  int numOfStrings = count_words(s);
  char *p, *t;
  char **tokens;
 
  if(numOfStrings == 0 ) return NULL;
  
  tokens = malloc ((numOfStrings + 1) * sizeof(char **));
  
  // check pointer is not null or else core dumped
  if ( tokens == (char **) NULL )  exit(-1);
  
  p = s; t = s;
  for (i= 0; i<numOfStrings; i++){
    p = word_start(t);
    t = word_terminator(p);
    tokens[i] = copy_str(p,t-p);
    t++;
  }
  
  // add null pointer to the end and return
  tokens[i] = (char *) NULL; 
  return tokens;
}

void print_tokens(char **s){
  char **t;
  t = s;
  while ( t != NULL ) {
    printf("%s\n",*t);
    ++t;
  }
  return;
}

void free_tokens(char **s){
  char **t = s;
  while ( *t != NULL ) {
    free(*t);
    t++;
  }
  free(s);
  return;
}
