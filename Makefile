CPP = g++
CFLAGS = -std=c++0x
SRCS = main.cpp Huffman.cpp Node.cpp PriorityQueue.cpp
OBJS = ${SRCS:.cpp=.o}
INCLS = ${SRCS:.cpp=.h}

p4: $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o p4

$(OBJS):
	$(CPP) $(CFLAGS) -c $*.cpp

depend: Makefile.dep
	$(CPP) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) Makefile Makefile.dep inputFile1.txt inputFile2.txt

clean:
	rm -f *.o a.out core

include Makefile.dep


