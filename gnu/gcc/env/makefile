main:main.o env.o
	gcc -o main main.o env.o
main.o:main.c env.h
	gcc -c main.c
env.o:env.c
	gcc -c env.c
clean:
	rm -f *.o
	rm -f main
	rm -f *~
