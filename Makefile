# A stub Makefile making your life easier.

.PHONY: all clean

all:
	${MAKE} -C src

clean:
	${MAKE} -C src clean
