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
	dot -Tps digraph-1-compo.dot -o outfile4.ps
	dot -Tps digraph-1-strong_orientation.dot -o outfile5.ps
	dot -Tps digraph-1-strong_orientationfc.dot -o outfile6.ps
	open *.ps
clean:
	rm -rf *.o main libfonctions.a *.dot outfi*
.PHONY: clean
