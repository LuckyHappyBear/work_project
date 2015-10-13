libshared_test.so:shared_test.o
	gcc -fPIC -shared -o libshared_test.so shared_test.o
shared_test.o:shared_test.c
	gcc -fPIC -c shared_test.c
clean:
	rm -f *~
	rm -f shared_test.o
	rm -f libshared_test.so
