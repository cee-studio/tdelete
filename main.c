#include <stdio.h>
#include <string.h>
#ifndef __MUSLC__
#include <search.h>
#define TSEARCH  tsearch
#define TDELETE  tdelete
#else
#include "tsearch.h"
#define TSEARCH  xtsearch
#define TDELETE  xtdelete
#endif

static void *root = NULL;

static int
compare(const void *pa, const void *pb)
{
   char * sa = (char *) pa;
   char * sb = (char *) pb;
   return strcmp (sa, sb);
}

static char  strings[8][64] = { 0 };

int main(void)
{
   int i;
   char * ptr;
   void *  ret;

   for (i = 0; i < 4; i++) {
       ptr = strings[i];
       sprintf(ptr, "%d", i);
       TSEARCH (ptr, &root, compare);
   }
   for (i = 0; i < 4; i++) {
       ptr = strings[i];
       fprintf (stderr, "\n  call tdelete to delete %s \n", ptr);
       ret = TDELETE (ptr, &root, compare);
       fprintf (stderr, "  tdelete returns \e[0;37m%p\e[0m\n", ret);
       fprintf (stderr, "  root is %p\n", root);       
   }
   return 0;
}

