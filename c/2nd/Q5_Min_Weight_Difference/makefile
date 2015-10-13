Min_Difference:main.o Min_Difference.o
	gcc -o Min_Difference main.o Min_Difference.o
main.o:main.c Min_Difference.h
	gcc -c main.c
Min_Difference.o:Min_Difference.c
	gcc -c Min_Difference.c
clean:
	rm -f Min_Difference
	rm -f *.o
	rm -f *~
