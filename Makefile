CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = rule_engine

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) src/*.o

lint:
	clang-tidy src/*.cpp -- -std=c++17 -I./src

format:
	clang-format -i src/*.cpp src/*.hpp