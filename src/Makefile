OBJS = grade.o inquire.o sort.o main.o

all: ${EXENAME}${SUFFIX}

${EXENAME}${SUFFIX}: ${OBJS}
	${LD} ${LDFLAGS} -o $@ $^

clean:
	${RM} ${RMFLAGS} *.o
	${RM} ${RMFLAGS} ${EXENAME}.a
	${RM} ${RMFLAGS} ${EXENAME}${SUFFIX}

%.o: %.cpp
	${CC} ${CPPFLAGS} ${CFLAGS} -c -o $@ $^
