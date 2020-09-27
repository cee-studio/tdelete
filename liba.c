#include <stdio.h>
char buf[100][100];

int i = 0;
void * malloc(unsigned int s) {
  i ++;
  char * p =  buf[i];

  fprintf (stderr, "  allocate %p\n", p);
  return p;
}

void free(void * p) {
  fprintf (stderr, "  free \e[0;31m%p\e[0m\n", p);
  return;
}


