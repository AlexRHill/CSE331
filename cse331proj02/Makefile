CXX=g++
CXXFLAGS=-std=c++11
EXECUTABLE=prog

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.h%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(EXECUTABLE) $^

%.o: %.c
	$(CXX) -o $@ -c $<

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)
CXX=g++
CXXFLAGS=-std=c++11
EXECUTABLE=prog

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.h%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(EXECUTABLE) $^

%.o: %.c
	$(CXX) -o $@ -c $<

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)
