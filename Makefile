CPPFLAGS= -O3 -Wall -Wextra -pedantic -std=c++20 -Ilib -Iinclude
sources=$(wildcard src/*.cpp)
objects=$(subst .cpp,.o,$(sources))
testsrc=$(wildcard tests/*cpp)
testobjects=$(subst .cpp,.o,$(testsrc))
underTest=$(filter-out src/main.o,$(objects))

all: testsuite aoc21

aoc21: $(objects)
	./testsuite
	$(CXX) $(CPPFLAGS) $^ -o $@

testsuite: $(testobjects) $(underTest)
	$(CXX) $(CPPFLAGS) $^ -o $@

clean:
	$(RM) aoc21 testsuite $(objects) $(testobjects)
