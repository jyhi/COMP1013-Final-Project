OBJS = grade.o inquire.o sort.o main.o

all: ${EXENAME}${SUFFIX}

${EXENAME}${SUFFIX}: ${OBJS}
	${LD} ${LDFLAGS} -o $@ $^

clean:
	${RM} ${RMFLAGS} *.o
	${RM} ${RMFLAGS} ${EXENAME}${SUFFIX}

main.o: grade.hpp inquire.hpp sort.hpp

%.o: %.cpp
	${CC} ${CPPFLAGS} ${CFLAGS} -c -o $@ $<
