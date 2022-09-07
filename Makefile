CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o canvas.o toolbox.o
EXEC = escape

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c canvas.h
	$(CC) -c main.c $(CFLAGS)

canvas.o : canvas.c canvas.h
	$(CC) -c canvas.c $(CFLAGS)

toolbox.o : toolbox.c toolbox.h
	$(CC) -c toolbox.c $(CFLAGS)

clean :
	rm -f $(EXEC) $(OBJ)

# make clean <- will always run (will never prompt "make: 'clean' up to date") 
# since there will be no file called "clean" be made as a result of this operation

#
# How to use Makefile
# -------------------
# make <- will look for the default file named Makefile, build the first target
# make Makefile <- can explicitely define the name of the Makefile
# 
# How to use Makefile to build targets individually
# --------------------------------------------------
# make <target>
# make escape <- build the target "escape"
# make main.o <- build the target "main.o" 
# make canvas.o <- build the target "canvas.o"
# make toolbox.o <- build the target "toolbox.o"
# make clean <- build the target "clean"