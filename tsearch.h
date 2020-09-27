/* AVL tree height < 1.44*log2(nodes+2)-0.3, MAXH is a safe upper bound.  */
#define MAXH (sizeof(void*)*8*3/2)

struct node {
	const void *key;
	void *a[2];
	int h;
};

int __tsearch_balance(void **);

extern void *xtsearch(const void *key, void **rootp,
                     int (*compar)(const void *, const void *));

extern void *xtfind(const void *key, void *const *rootp,
                   int (*compar)(const void *, const void *));

extern void *xtdelete(const void *key, void **rootp,
                       int (*compar)(const void *, const void *));