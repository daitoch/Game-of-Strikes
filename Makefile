output: main.o fileLib.o gameLib.o
	gcc main.o fileLib.o gameLib.o -o output
	
main.o: main.c
	gcc -c main.c
fileLib.o: fileLib.c fileLib.h
	gcc -c fileLib.c
gameLib.o: gameLib.c gameLib.h
	gcc -c gameLib.c

clean:
	rm *.o output