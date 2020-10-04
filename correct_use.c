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
   void * root_before_tdelete;

   for (i = 0; i < 4; i++) {
       ptr = strings[i];
       sprintf(ptr, "%d", i);
       TSEARCH (ptr, &root, compare);
   }
   
   root_before_tdelete = root; // need to preseve the root before its adjustment
   fprintf (stderr, "  root_before_tdelete is %p\n", root_before_tdelete);
   for (i = 0; i < 4; i++) {
       ptr = strings[i];
       fprintf (stderr, "\n  call tdelete to delete %s \n", ptr);
       ret = TDELETE (ptr, &root, compare);
       // as root might have been adjusted, only root_before_delete 
       // can be used to compare with ret.
       if (root_before_tdelete == ret && root != ret) {
          fprintf (stderr, "  root_before_tdelete is %p\n", root_before_tdelete);
          fprintf (stderr, "  root is %p\n", root_before_tdelete);
	      fprintf (stderr, "  a dangling pointer %p is returned\n", ret);
       }
       fprintf (stderr, "  tdelete returns \e[0;37m%p\e[0m\n", ret);
       fprintf (stderr, "  root is %p\n", root);       
       // need to preseve the current root for the next loop
       root_before_tdelete = root;
   }
   return 0;
}

