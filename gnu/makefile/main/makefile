main:main.c ../sharedLib/libshared_test.so ../staticLib/libstatic_test.a
	gcc main.c  -L../staticLib -lstatic_test -L../sharedLib -lshared_test -o main
clean:
	rm -f main
	rm -f *~
