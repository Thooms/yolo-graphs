
CC=clang++
CFLAGS= -Wall -Werror -pedantic -std=c++11 -Wno-error=c++98-compat
OBJECTFLAG= -c
EXEC=yolo-graphs

SOURCEDIR=src
LIBSRCDIR=$(SOURCEDIR)/lib
TESTSRCDIR=$(SOURCEDIR)/examples

BUILDDIR=build

LIBSOURCES=$(wildcard $(LIBSRCDIR)/*.cc)
LIBOBJECTS=$(patsubst $(LIBSRCDIR)/%.cc, $(BUILDDIR)/%.o, $(LIBSOURCES))

SOURCES=$(wildcard $(TESTSRCDIR)/*.cc)
EXECS=$(patsubst $(TESTSRCDIR)/%.cc, %, $(SOURCES))

all: tests

tests: lib $(EXECS)

$(EXECS): %: $(TESTSRCDIR)/%.cc  
	$(CC) $(CFLAGS) $< $(LIBOBJECTS) -I $(LIBSRCDIR) -o $@

lib: $(LIBOBJECTS)

$(LIBOBJECTS): $(BUILDDIR)/%.o: $(LIBSRCDIR)/%.cc
	$(CC) $(CFLAGS) $(OBJECTFLAG) $< -o $@


rebuild: mrproper all

clean:
	rm -rf $(BUILDDIR)/*.o

mrproper: clean
	rm -rf $(EXECS)
	rm -rf *.dot
	rm -rf *.svg
	rm -rf main{1,2,3,4}
