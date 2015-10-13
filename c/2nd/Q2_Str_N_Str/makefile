Str_N_Str:main.o Str_N_Str.o
	gcc -o Str_N_Str main.o Str_N_Str.o
main.o:Str_N_Str.h main.c
	gcc -c main.c
Str_N_Str.o:Str_N_Str.c
	gcc -c Str_N_Str.c
clean:
	rm -f *.o
	rm -f *~
	rm -f Str_N_Str
