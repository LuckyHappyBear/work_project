main:main.o endian.o
	gcc -o main main.o endian.o
main.o:main.c endian.h
	gcc -c main.c
endian.o:endian.c
	gcc -c endian.c
clean:
	rm -f *~
	rm -f main
	rm -f *.o
