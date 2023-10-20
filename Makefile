all: algo1.c pile.c 
	gcc -g algo1.c pile.c -o algo1
	gcc -g algo2.c pile.c -o algo2
	gcc -g algo3.c pile.c -o algo3
	gcc -g algo4.c pile.c -o algo4
	gcc -g test.c pile.c -o test


clean:
	rm -f algo1 algo2 algo3 algo4 test