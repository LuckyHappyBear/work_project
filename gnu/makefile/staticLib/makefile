static_test.a:static_test.o
	ar crv libstatic_test.a static_test.o
static_test.o:static_test.c static_test.h
	gcc -c static_test.c
clean:
	rm -f *~
	rm -f static_test.o
	rm -f libstatic_test.a
