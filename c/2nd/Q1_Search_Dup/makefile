Search_Dup:main.o Search_Dup.o
	gcc -g -o Search_Dup main.o Search_Dup.o
main.o:main.c Search_Dup.h
	gcc -c main.c
Search_Dup.o:
	gcc -c Search_Dup.c
clean:
	rm -f *.o
	rm -f *~
	rm -f Search_Dup
