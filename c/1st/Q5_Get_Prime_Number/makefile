Get_Prime_Number:Get_Prime_Number.o main.o
	gcc -o Get_Prime_Number main.o Get_Prime_Number.o -lm
main.o:Get_Prime_Number.h
	gcc -c main.c
Get_Prime_Number.o:Get_Prime_Number.c
	gcc -c Get_Prime_Number.c
clean:
	rm -f Get_Prime_Number
	rm -f *~
	rm -f *.o
