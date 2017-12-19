OBJS = grade.o inquire.o sort.o main.o

all: grading${SUFFIX}

grading${SUFFIX}: ${OBJS}
	${LD} ${LDFLAGS} -o $@ $^

clean:
	${RM} ${RMFLAGS} *.o
	${RM} ${RMFLAGS} grading.a

%.o: %.cpp
	${CC} ${CPPFLAGS} ${CFLAGS} -c -o $@ $^
