
CC=clang++
CFLAGS=-W -Wall -Werror -pedantic -std=c++11 -c
LDFLAGS=
EXEC=yolo-graphs

SOURCEDIR=src
BUILDDIR=build

SOURCES=$(wildcard $(SOURCEDIR)/*.cc)
OBJECTS=$(patsubst $(SOURCEDIR)/%.cc, $(BUILDDIR)/%.o, $(SOURCES))

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $^ -o $@

$(OBJECTS): $(BUILDDIR)/%.o: $(SOURCEDIR)/%.cc
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm -rf $(BUILDDIR)/*.o

mrproper: clean
	rm -rf $(EXEC)
