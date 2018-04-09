CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CSSFLAGS += -pendantic-errors
CXXFLAGS += -g

OBJS = main.o Board.o Ant.o

SRCS = main.cpp Board.cpp Ant.cpp

HEADERS = Board.hpp Ant.hpp

project1: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o project1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm main.o
	rm Board.o
	rm Ant.o
	rm project1
	