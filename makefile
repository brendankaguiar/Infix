# the compiler: g++ for C++ program
CXX = g++ --std=c++11

#compiler flags:
# -g	adds debugging inf to executable file
# -Wall	turns on most, not all, compiler warnings
CXXFLAGS = -Wall -g

# the build target executable:

Exercise1: postfix.o StackLinked.o #first line lists dependency of trunk.
	$(CXX) $(CXXFLAGS) -o Exercise1 postfix.o StackLinked.o

#next line is building the object files with its dependencies.
postfix.o: StackLinked.cpp StackLinked.h Stack.h
	$(CXX) $(CXXFLAGS) -c postfix.cpp 

StackLinked.o: StackLinked.h Stack.h

#indented line, known as generator line, not needed after first one bc of CXX.
clean:
	rm Exercise1 postfix.o StackLinked.o
