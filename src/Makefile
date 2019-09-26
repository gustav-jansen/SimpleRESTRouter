CPP=g++
CFLAGS:=-O3 -Wall -Wextra -std=c++11
ifdef DEBUG
    CFLAGS+=-DDEBUG -Og -g
endif

libname = srest.a
objects = Message.o SimpleHTTPParser.o InetAddress.o SocketListener.o SimpleRESTManager.o

all: library server.o
	${CPP} ${CFLAGS} -o server.x server.o ${objects} -lpthread

library: ${objects}
	rm -f ${libname}
	ar qc ${libname} ${objects}
	
%.o: %.cpp
	${CPP} ${CFLAGS} -c $< -o $@
.PHONY.: clean
clean:
	rm -f *.o *.x

