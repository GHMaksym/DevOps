CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = shxcalc

SRCS = main.cpp ShxCalculator.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
