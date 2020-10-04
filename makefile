all: test_glibc test_musl_libc

liba.so: liba.c
	@$(CC) -c -fPIC $<
	@$(CC) -o $@ -shared liba.o

glibc: main.c
	@$(CC) -o $@ $<


test_glibc: glibc liba.so
	$(info  )
	$(info  Testing glibc's tdelete)
	$(info  )
	@env LD_PRELOAD=$(shell pwd)/liba.so  ./glibc


musl_libc: main.c
	@$(CC) -o $@ -D__MUSLC__ main.c tdelete.c tsearch.c


test_musl_libc: musl_libc liba.so
	$(info  )
	$(info  Testing musl libc's tdelete)
	$(info  )
	@env LD_PRELOAD=$(shell pwd)/liba.so ./musl_libc


clean:
	@rm -f *.o *.so
	@rm -f glibc musl_libc
