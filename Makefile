CPPFLAGS=-Wall -Wextra -pedantic -std=c++20 -Ilib -Iinclude
sources=$(wildcard src/*.cpp)
objects=$(subst .cpp,.o,$(sources))

aoc21: $(objects)
	$(CXX) $(CPPFLAGS) $^ -o $@

clean:
	$(RM) aoc21 $(objects)
