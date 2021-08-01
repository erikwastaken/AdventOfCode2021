CPPFLAGS=-Wall -Wextra -pedantic -std=c++20
sources=$(wildcard src/*.cpp)
objects=$(subst .cpp,.o,$(sources))

aoc21: $(objects)
	$(CXX) $(CPPFLAGS) $^ -o $@
