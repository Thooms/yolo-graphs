
CC=clang++
CFLAGS= -Wall -Werror -pedantic -std=c++11 -c -Wno-error=c++98-compat
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

rebuild: mrproper all

clean:
	rm -rf $(BUILDDIR)/*.o

mrproper: clean
	rm -rf $(EXEC)
