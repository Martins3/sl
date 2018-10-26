CC = clang++
FLAG = -std=c++14 -g -Wall
TARTGET = Review

CPP_SOURCES = $(wildcard *.cpp)
CPP_HEADERS = $(wildcard ./Include/*.hpp) 
OBJ = ${CPP_SOURCES:.cpp=.o} 


# 需要实现如何的效果
${TARTGET}: ${OBJ}
	${CC} ${FLAG} -o $@ $^


# all: library.cpp main.cpp
# In this case:
    # $@ evaluates to all
    # $< evaluates to library.cpp
    # $^ evaluates to library.cpp main.cpp
%.o: %.cpp ${HEADERS}
	${CC} ${FLAG} -c $< -o $@


run: ${TARTGET}
	./${TARTGET}

main: main.cpp
	clang++ -S  main.cpp -std=c++11

.PHONY: clean run


clean:
	rm -f *.o
	rm -f ${TARTGET}
