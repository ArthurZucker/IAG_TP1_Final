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
	dot -Tpdf digraph-1-strong_orientationfc.dot -o ./Images/orifortecfc.pdf
	dot -Tpdf digraph-1-strong_orientation.dot	-o ./Images/oriforte.pdf
	dot -Tpdf digraph-1-predfs.dot	-o ./Images/predf.pdf
	dot -Tpdf digraph-1-postdfs.dot  -o ./Images/postdfs.pdf
	dot -Tpdf digraph-1-compoaprèscfc.dot -o ./Images/compoaprèscfc.pdf

clean:
	rm -rf *.o main libfonctions.a *.dot *.ps
.PHONY: clean
