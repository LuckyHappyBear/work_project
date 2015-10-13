main:main.o Cal_Exp.o Element_Stack.o Float_Stack.o
	gcc -g -o main main.o Cal_Exp.o
main.o:
	gcc -c main.c
Cal_Exp.o:
	gcc -c Cal_Exp.c
Element_Stack.o:
	gcc -c Element_Stack.c
Float_Stack.o:
	gcc -c Float_Stack.c

clean:
	rm -f *~
	rm -f *.o
	rm -f main
