CC = g++
LD = g++

CP = cp
RM = rm
RMFLAGS = -f

EXENAME = grading
# SUFFIX = .exe

ifdef DEBUG
CFLAGS   = -std=c++11 -O0 -fstack-protector-all --param=ssp-buffer-size=4 -ggdb -Wall -Wextra -pedantic
CPPFLAGS =
LDFLAGS  =
else
CFLAGS   = -std=c++11 -O2 -fstack-protector-strong --param=ssp-buffer-size=4 -fPIE -Wall -Wextra -pedantic
CPPFLAGS = -D_FORTIFY_SOURCE=2
LDFLAGS  = -pie
endif

OBJS = grade.o inquire.o sort.o main.o node.o

.PHONY: all clean

all: ${EXENAME}${SUFFIX}

${EXENAME}${SUFFIX}: ${OBJS}
	${LD} ${LDFLAGS} -o $@ $^

clean:
	${RM} ${RMFLAGS} *.o *.gch
	${RM} ${RMFLAGS} ${EXENAME}${SUFFIX}

main.o: grade.hpp inquire.hpp sort.hpp utils.hpp node.hpp

%.o: %.cpp
	${CC} ${CPPFLAGS} ${CFLAGS} -c -o $@ $<
