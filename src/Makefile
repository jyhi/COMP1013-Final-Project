OBJS = grade.o inquire.o sort.o main.o node.o

all: ${EXENAME}${SUFFIX}

${EXENAME}${SUFFIX}: ${OBJS}
	${LD} ${LDFLAGS} -o $@ $^

clean:
	${RM} ${RMFLAGS} *.o *.gch
	${RM} ${RMFLAGS} ${EXENAME}${SUFFIX}

main.o: grade.hpp inquire.hpp sort.hpp utils.hpp node.hpp

%.o: %.cpp
	${CC} ${CPPFLAGS} ${CFLAGS} -c -o $@ $<
