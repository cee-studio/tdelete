all:

liba.so: liba.c
	gcc -c -fPIC $<
	gcc -o $@ -shared liba.o

glibc: prog.c
	gcc -o $@ $<


test_glibc: glibc liba.so
	LD_PRELOAD=$(shell pwd)/liba.so  ./glibc


musl_libc: prog.c
	gcc -o $@ -D__MUSLC__ prog.c tdelete.c tsearch.c


test_musl_libc: musl_libc liba.so
	LD_PRELOAD=$(shell pwd)/liba.so ./musl_libc


clean:
	@rm -f *.o *.so
	@rm -f glibc musl_libc
