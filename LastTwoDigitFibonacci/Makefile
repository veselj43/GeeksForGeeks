CXX=g++
CXXFLAGS= -Wall -pedantic -g -std=c++11
LIBS=
#-lcrypto -lssl
EXECUTABLE=main

run: compile
	./$(EXECUTABLE)

compile: ${EXECUTABLE}

%: %.c
	$(CXX) $(CXXFLAGS) -o $@ $< $(LIBS)