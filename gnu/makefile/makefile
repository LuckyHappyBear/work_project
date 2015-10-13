main_test:./main/main.c libshared_test.so libstatic_test.a
	gcc -o test ./main/main.c libshared_test.so libstatic_test.a

libstatic_test.a:./staticLib/static_test.o
	ar crv libstatic_test.a ./staticLib/static_test.o
static_test.o:./staticLib/static_test.c
	gcc -c ./staticLib/static_test.c -o ./staticLib/static_test.o

libshared_test.so:./sharedLib/shared_test.c
	gcc -fPIC -shared -o libshared_test.so ./sharedLib/shared_test.c

clean:
	rm -f libshared_test.so
	rm -f libstatic_test.a
	rm -f ./staticLib/static_test.o
	rm -f main_test
