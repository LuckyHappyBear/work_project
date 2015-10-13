Error_Code_Gen: Error_Code_Gen.o main.o
	gcc -o Error_Code_Gen main.o Error_Code_Gen.o
main.o: main.c Error_Code_Gen.h
	gcc -c main.c
Error_Code_Gen.o: Error_Code_Gen.c Error_Code_Gen.h
	gcc -c Error_Code_Gen.c
clean:
	rm -f Error_Code_Gen
	rm -f *~
	rm -f *.o
