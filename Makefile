all: console.o processor.o
	gcc -o console console.o
	gcc -o processor processor.o
	
console.o: console.c
	gcc -c console.c
	
processor.o: processor.c
	gcc -c processor.c
	
clean:
	rm *.o
