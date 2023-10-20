all: algo1.c pile.c 
	gcc -g algo1.c pile.c -o test1
	gcc -g algo2.c pile.c -o test2
clean:
	rm -f test1 test2