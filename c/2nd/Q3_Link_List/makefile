Link_List:main.o Link_List.o
	gcc -o Link_List main.o Link_List.o
main.o:main.c Link_List.h
	gcc -c main.c
Link_List.o:Link_List.c Link_List.h
	gcc -c Link_List.c
clean:
	rm -f *.o
	rm -f *~
	rm -f Link_List
