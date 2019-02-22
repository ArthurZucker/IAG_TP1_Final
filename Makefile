CC = gcc
LDFLAGS = -Wall -g
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
	valgrind --leak-check=full --track-origins=yes ./main
	dot -Tps digraph-1-strong_orientationfc.dot -o orifortecfc.ps
	dot -Tps digraph-1-strong_orientation.dot	-o oriforte.ps
	dot -Tps digraph-1-predfs.dot	-o predf.ps
	dot -Tps digraph-1-postdfs.dot  -o postdfs.ps
	dot -Tps digraph-1-compoaprèscfc.dot -o compoaprèscfc.ps

clean:
	rm -rf *.o main libfonctions.a *.dot *.ps
.PHONY: clean
