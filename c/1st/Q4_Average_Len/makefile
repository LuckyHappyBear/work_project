Average_Len:Average_Len.o main.o
	gcc -o Average_Len Average_Len.o main.o
main.o:Average_Len.h main.c
	gcc -c main.c
Average_Len.o:Average_Len.h Average_Len.c
	gcc -c Average_Len.c
clean:
	rm -f Average_Len
	rm -f *~
	rm -f *.o
