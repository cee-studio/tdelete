#include <stdio.h>
#include <string.h>

/*
 * a demo to show how to determin the
 * return value of tdelete is a dangling pointer
 *
 */
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

   // prepare the data
   for (i = 0; i < 4; i++) {
       ptr = strings[i];
       sprintf(ptr, "%d", i);
       tsearch (ptr, &root, compare);
   }

   // need to preseve the root before its adjustment
   root_before_tdelete = root; 
   for (i = 0; i < 4; i++) {
       ptr = strings[i];
       ret = tdelete (ptr, &root, compare);

       // as root might have been adjusted, only root_before_delete 
       // can be used to compare with ret.
       if (root_before_tdelete == ret && root != root_before_tdelete) 
	      fprintf (stderr, "  a dangling pointer %p is returned\n", ret);
       
       // need to preseve the current root for the next loop
       root_before_tdelete = root;
   }
   return 0;
}

