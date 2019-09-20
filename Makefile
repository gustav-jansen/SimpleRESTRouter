CPP=g++
CFLAGS:=-O3 -Wall -Wextra -std=c++11
ifdef DEBUG
    CFLAGS+=-DDEBUG -Og -g
endif

objects = Message.o SimpleHTTPParser.o InetAddress.o SocketListener.o SimpleRESTManager.o

all: ${objects} server.o
	${CPP} ${CFLAGS} -o server.x server.o ${objects}

%.o: %.cpp
	${CPP} ${CFLAGS} -c $< -o $@
.PHONY.: clean
clean:
	rm -f *.o *.x

