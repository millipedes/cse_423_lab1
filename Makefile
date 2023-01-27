CC=gcc -g -Wall -Wextra
CFILES=$(wildcard src/*/*.c)
HFILES=$(wildcard src/*/include/*.h)
OBJFILES=$(CFILES:.c=.o)
OBJPATH=src/objects/
EXEFILE=bin/puny

LX=flex
FLEXFILE=flex/punylex.l
FLEXOUT=src/lexer/punylex.c
FLEXHOUT=src/lexer/include/punylex.h
FLEX_PATH:=$(shell dirname $(shell which flex))
LIB_PATH:=$(shell readlink -f "$(FLEX_PATH)/../lib")

all: flex_rule $(OBJFILES) $(FLEXFILE)
	$(CC) -L $(LIB_PATH) $(OBJFILES) -o $(EXEFILE) -lm -lfl

flex_rule:
	$(LX) -o $(FLEXOUT) --header-file=$(FLEXHOUT) $(FLEXFILE)

%.o: %.c $(HFILES)%.h
	$(CC) -c $(CFILES) $< -o $@ -lm -lfl

vim:
	nvim $(CFILES) $(FLEXFILE)

vimh:
	nvim $(HFILES) 

run:
	$(EXEFILE)

debug:
	gdb -q $(EXEFILE)

memcheck:
	valgrind $(EXEFILE) --leak-check=full --read-var-info

feh:
	feh docs/uml.png&

plant:
	plantuml docs/uml.txt
	convert docs/uml.png -channel RGB -negate docs/uml.png

git-update:
	git add Makefile README.md src/ flex/ bin/ docs/ idata/

clean:
	rm $(OBJFILES)
	rm $(EXEFILE)
