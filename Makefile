CC = clang++
FLAG = -std=c++14 -g -Wall -DEBUG -pthread -I./include -I./test
TARTGET = ~/.Application/review


CPP_SOURCES = $(wildcard *.cpp ./test/*.cpp)
CPP_HEADERS = $(wildcard ./include/*.hpp ./test/*.hpp) 
OBJ = ${CPP_SOURCES:.cpp=.o} 


# 需要实现如何的效果
${TARTGET}: ${OBJ}
	${CC} ${FLAG} -o $@ $^


# all: library.cpp main.cpp
# In this case:
    # $@ evaluates to all
    # $< evaluates to library.cpp
    # $^ evaluates to library.cpp main.cpp
%.o: %.cpp ${CPP_HEADERS}
	${CC} ${FLAG} -c $< -o $@


run: ${TARTGET}
	${TARTGET}

test: ${TARTGET}
	${TARTGET} -d ~/.SpaceVim.d/translate/words.txt 

main: main.cpp
	clang++ -S  main.cpp -std=c++11

.PHONY: clean run


clean:
	rm -f *.o
	rm -f test/*.o
	rm -f ${TARTGET}
