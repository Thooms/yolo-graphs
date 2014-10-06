
CC=clang++
CFLAGS=-W -Wall -ansi -pedantic -std=c++11
LDFLAGS=
EXEC=yolo-graphs

clean:
	rm -rf *.o

mrproper: clean
	rm -rf build/$(EXEC)
