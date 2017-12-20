CC = gcc
AR = ar
LD = gcc

CP = cp
RM = rm
RMFLAGS = -f

EXENAME = grading
# SUFFIX = .exe

ifdef DEBUG
CFLAGS   = -O0 -fstack-protector-all --param=ssp-buffer-size=4 -ggdb -Wall -Wextra -pedantic
CPPFLAGS =
ARFLAGS  = rcs
LDFLAGS  =
else
CFLAGS   = -O2 -fstack-protector-strong --param=ssp-buffer-size=4 -fPIE -Wall -Wextra -pedantic
CPPFLAGS = -D_FORTIFY_SOURCE=2
ARFLAGS  = rcs
LDFLAGS  = -Wl,-O1,--sort-common,--as-needed -Wl,-z,relro,-z,now -pie
endif

export

.PHONY: all clean

all:
	${MAKE} -C src

clean:
	${MAKE} -C src clean
