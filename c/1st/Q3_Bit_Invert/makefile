Bit_Invert:Bit_Invert.o main.o
	gcc -o Bit_Invert Bit_Invert.o main.o
main.o:Bit_Invert.h main.c
	gcc -c main.c
Bit_Invert.o:Bit_Invert.c Bit_Invert.h
	gcc -c Bit_Invert.c
clean:
	rm -f Bit_Invert
	rm -f *~
	rm -f *.o
