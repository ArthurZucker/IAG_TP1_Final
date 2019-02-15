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
	dot -Tps digraph-1-predfs.dot -o outfile1.ps
	dot -Tps digraph-1-postdfs.dot -o outfile2.ps
	dot -Tps digraph-1-predfs_inverse.dot -o outfile3.ps
clean:
	rm -rf *.o main libfonctions.a graphique.dot outfile.ps outfile.pdf
.PHONY: clean
