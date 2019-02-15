CC = gcc
LDFLAGS = -Wall
LIB = $(wildcard *.c)
OBJ = $(LIB:.c=.o)
all: main
.depend:
	$(CC) -MM $(LIB)
%.o:%.c
	${CC} ${LDFLAGS} $^ -c -o $@
libfonctions.a: ${OBJ}
	ar -cru  $@ $^
	ranlib $@
main: ${OBJ} libfonctions.a
	$(CC) $(OBJ) -o $@
	./main
	dot -Tps graphique.dot -o outfile.ps
clean:
	rm -rf *.o main libfonctions.a graphique.dot outfile.ps outfile.pdf
.PHONY: clean
